/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_ASSETREPOSITORY_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_ASSETREPOSITORY_INCLUDED

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <type_traits>

#include <trans4/assets/AssetDescriptor.hpp>
#include <trans4/assets/AssetHandleResolver.hpp>
#include <trans4/assets/AssetSerializer.hpp>

namespace rpgtoolkit {

    using std::vector;
    using std::string;
    using std::unordered_map;
    using std::unique_ptr;

    /// Asset loading facade and cache mechanism. This class
    /// loads assets into memory and manages an asset cache
    /// to minimize load.

    struct AssetRepository {

        /// Pushes an asset resolver into the repository;
        /// asset resolvers generate asset handles based on
        /// asset descriptor URI schemes (e.g. files, network
        /// streams, memory buffers, etc).

        void
        push_resolver(unique_ptr<AssetHandleResolver> resolver) {
            if (resolver) {
                resolvers_.push_back(std::move(resolver));
            }
        }

        /// Pushes an asset serializer into the repository;
        /// asset serializers load asset data from an asset
        /// handle (file, network stream, etc).

        void
        push_serializer(unique_ptr<AssetSerializer> serializer) {
            if (serializer) {
                serializers_.push_back(std::move(serializer));
            }
        }


        /// Unloads and removes an asset in the repository
        /// referenced by the specified descriptor.

        void
        unload(AssetDescriptor const & descriptor) {
            assets_.erase(descriptor);
        }

        /// Loads an asset of the specified type from the
        /// asset repository.

        template<
            typename T,
            typename std::enable_if<
                    std::is_base_of<Asset, T>::value>::type* = nullptr>
        inline T *
        load(string const & uri, bool reload = false) {
            auto handle = load(uri, reload);
            return handle
                    ? dynamic_cast<T *>(handle->asset())
                    : nullptr;
        }

        /// Loads an asset into the repository.
        ///
        /// @param uri asset uri (e.g. file://C:/audio.mp3))
        /// @param reload if true, bypasses cache

        AssetHandle *
        load(string const & uri, bool reload = false) {
            return load(AssetDescriptor(0x00, uri), reload);
        }

        /// Loads an asset into the repository.
        ///
        /// @param descriptor asset descriptor (e.g. filename)
        /// @param reload if true, bypasses cache

        AssetHandle *
        load(AssetDescriptor const & descriptor, bool reload = false) {

            // Bypass cache if reload was requested; otherwise lookup the
            // asset descriptor in the asset cache and return the cached handle

            if (!reload) {
                auto query = assets_.find(descriptor);
                if (query != assets_.end()) {
                    return query->second.get();
                }
            }

            // Retrieve a resolver and serializer for the supplied descriptor

            auto resolver = this->resolver(descriptor);
            auto serializer = this->serializer(descriptor);

            // Resolve an asset handle given the asset descriptor, and then
            // load the referenced asset if it exists and add it to the
            // asset cache...

            if (resolver && serializer) {
                auto handle = resolver->resolve(descriptor);
                auto ptr = handle.get();
                if (handle) {
                    if (!handle->exists()) {
                        throw rpgtoolkit::Exception(
                                "The specified asset does not exist or could not be loaded.");
                    }
                    serializer->deserialize(*ptr);
                    assets_[descriptor] = std::move(handle);
                    return ptr;
                }
            }

            // Return nothing if there was no resolver, serializer, or cache
            // entry for the asset descriptor

            return nullptr;

        }

    private:

        /// Finds an asset resolver for the specified descriptor.
        /// The first registered compatible resolver is returned.

        AssetHandleResolver *
        resolver(AssetDescriptor const & descriptor) {
            for (auto & resolver : resolvers_) {
                if (resolver->resolvable(descriptor)) {
                    return resolver.get();
                }
            }
            return nullptr;
        }

        /// Finds an asset serializer for the specified descriptor.
        /// The first registered compatible serializer is returned.

        AssetSerializer *
        serializer(AssetDescriptor const & descriptor) {
            for (auto & serializer : serializers_) {
                if (serializer->serializable(descriptor)
                        || serializer->deserializable(descriptor)) {
                    return serializer.get();
                }
            }
            return nullptr;
        }

        vector<unique_ptr<AssetHandleResolver> > resolvers_;
        vector<unique_ptr<AssetSerializer> > serializers_;

        unordered_map<AssetDescriptor, unique_ptr<AssetHandle>,
                AssetDescriptorHash, AssetDescriptorEquals> assets_;

    };

}

#endif
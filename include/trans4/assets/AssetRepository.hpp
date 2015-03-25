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

#include "common/Exception.h"

#include "assets/AssetDescriptor.hpp"
#include "assets/AssetHandleResolver.hpp"
#include "assets/AssetSerializer.hpp"

namespace rpgtoolkit {

    using std::vector;
    using std::string;
    using std::unordered_map;
    using std::unique_ptr;

    /// Asset loading facade and cache mechanism. This class
    /// loads assets into memory and manages an asset cache
    /// to minimize load.

    struct AssetRepository {

        /// Registers an asset resolver with the repository;
        /// asset resolvers generate asset handles based on
        /// asset descriptor URI schemes (e.g. files, network
        /// streams, memory buffers, etc).

        template <typename T> void
        RegisterResolver() {
            RegisterResolver(std::unique_ptr<T>(new T()));
        }

        /// Registers an asset resolver with the repository;
        /// asset resolvers generate asset handles based on
        /// asset descriptor URI schemes (e.g. files, network
        /// streams, memory buffers, etc).

        void
        RegisterResolver(unique_ptr<AssetHandleResolver> resolver) {
            if (resolver) {
                resolvers_.push_back(std::move(resolver));
            }
        }

        /// Registers an asset serializer with the repository;
        /// asset serializers load asset data from an asset
        /// handle (file, network stream, etc).

        template <typename T> void
        RegisterSerializer() {
            RegisterSerializer(std::unique_ptr<T>(new T()));
        }

        /// Registers an asset serializer with the repository;
        /// asset serializers load asset data from an asset
        /// handle (file, network stream, etc).

        void
        RegisterSerializer(unique_ptr<AssetSerializer> serializer) {
            if (serializer) {
                serializers_.push_back(std::move(serializer));
            }
        }


        /// Unloads and removes an asset in the repository
        /// referenced by the specified descriptor.

        void
        Unload(AssetDescriptor const & descriptor) {
            assets_.erase(descriptor);
        }

        /// Loads an asset of the specified type from the
        /// asset repository.

        template<
            typename T,
            typename std::enable_if<
                    std::is_base_of<Asset, T>::value>::type* = nullptr>
        inline T *
        Load(string const & uri, bool reload = false) {
            auto handle = Load(uri, reload);
            return handle
                    ? dynamic_cast<T *>(handle->GetAsset())
                    : nullptr;
        }

        /// Loads an asset into the repository.
        ///
        /// \param uri asset uri (e.g. file://C:/audio.mp3))
        /// \param reload if true, bypasses cache

        AssetHandle *
        Load(string const & uri, bool reload = false) {
            return Load(AssetDescriptor(0x00, uri), reload);
        }

        /// Loads an asset into the repository.
        ///
        /// \param descriptor asset descriptor (e.g. filename)
        /// \param reload if true, bypasses cache

        AssetHandle *
        Load(AssetDescriptor const & descriptor, bool reload = false) {

            // Bypass cache if reload was requested; otherwise lookup the
            // asset descriptor in the asset cache and return the cached handle

            if (!reload) {
                auto query = assets_.find(descriptor);
                if (query != assets_.end()) {
                    return query->second.get();
                }
            }

            // Retrieve a resolver and serializer for the supplied descriptor

            auto resolver = FindResolver(descriptor);
            auto serializer = FindSerializer(descriptor);

            // Resolve an asset handle given the asset descriptor, and then
            // load the referenced asset if it exists and add it to the
            // asset cache...

            if (resolver && serializer) {
                auto handle = resolver->Resolve(descriptor);
                auto ptr = handle.get();
                if (handle) {
                    if (!handle->Exists()) {
                        throw clio::Exception(
                                "The specified asset does not exist or could not be loaded.");
                    }
                    serializer->Deserialize(*ptr);
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
        FindResolver(AssetDescriptor const & descriptor) {
            for (auto & resolver : resolvers_) {
                if (resolver->IsResolvable(descriptor)) {
                    return resolver.get();
                }
            }
            return nullptr;
        }

        /// Finds an asset serializer for the specified descriptor.
        /// The first registered compatible serializer is returned.

        AssetSerializer *
        FindSerializer(AssetDescriptor const & descriptor) {
            for (auto & serializer : serializers_) {
                if (serializer->CanSerialize(descriptor)
                        || serializer->CanDeserialize(descriptor)) {
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
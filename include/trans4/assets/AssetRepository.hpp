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

#include "common/Exception.hpp"

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
        RegisterResolver(unique_ptr<AssetHandleResolver> resolver);

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
        RegisterSerializer(unique_ptr<AssetSerializer> serializer);

        /// Unloads and removes an asset in the repository
        /// referenced by the specified descriptor.

        void
        Unload(AssetDescriptor const & descriptor);

        void
        Unload(string const & uri);

        /// Loads an asset of the specified type from the
        /// asset repository.

        template<
            typename T,
            typename std::enable_if<
                    std::is_base_of<Asset, T>::value>::type* = nullptr>
        inline T *
        Load(string const & uri, bool reload = false) {
            auto handle = Load(AssetDescriptor(0x00, uri), reload);
            return handle
                    ? dynamic_cast<T *>(handle->GetAsset())
                    : nullptr;
        }

        /// Loads an asset into the repository.
        ///
        /// \param descriptor asset descriptor (e.g. filename)
        /// \param reload if true, bypasses cache

        AssetHandle *
        Load(AssetDescriptor const & descriptor, bool reload = false);

    private:

        /// Finds an asset resolver for the specified descriptor.
        /// The first registered compatible resolver is returned.

        AssetHandleResolver *
        FindResolver(AssetDescriptor const & descriptor);

        /// Finds an asset serializer for the specified descriptor.
        /// The first registered compatible serializer is returned.

        AssetSerializer *
        FindSerializer(AssetDescriptor const & descriptor);

        vector<unique_ptr<AssetHandleResolver> > resolvers_;
        vector<unique_ptr<AssetSerializer> > serializers_;

        unordered_map<AssetDescriptor, unique_ptr<AssetHandle>,
                AssetDescriptorHash, AssetDescriptorEquals> assets_;

    };

}

#endif
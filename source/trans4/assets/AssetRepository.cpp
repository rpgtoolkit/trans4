/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "assets/AssetRepository.hpp"

namespace rpgtoolkit {

    void
    AssetRepository::RegisterResolver(unique_ptr<AssetHandleResolver> resolver) {
        if (resolver) {
            resolvers_.push_back(std::move(resolver));
        }
    }

    /// Registers an asset serializer with the repository;
    /// asset serializers load asset data from an asset
    /// handle (file, network stream, etc).

    void
    AssetRepository::RegisterSerializer(unique_ptr<AssetSerializer> serializer) {
        if (serializer) {
            serializers_.push_back(std::move(serializer));
        }
    }

    void
    AssetRepository::Unload(AssetDescriptor const & descriptor) {
        assets_.erase(descriptor);
    }

    void
    AssetRepository::Unload(string const & uri) {
        Unload(AssetDescriptor(0x00, uri));
    }

    AssetHandle *
    AssetRepository::Load(AssetDescriptor const & descriptor, bool reload) {

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
            if (handle && handle->Exists()) {
                serializer->Deserialize(*ptr);
                assets_[descriptor] = std::move(handle);
                return ptr;
            }
        }

        // Return nothing if there was no resolver, serializer, or cache
        // entry for the asset descriptor

        return nullptr;

    }

    AssetHandleResolver *
    AssetRepository::FindResolver(AssetDescriptor const & descriptor) {
        for (auto & resolver : resolvers_) {
            if (resolver->IsResolvable(descriptor)) {
                return resolver.get();
            }
        }
        return nullptr;
    }

    AssetSerializer *
    AssetRepository::FindSerializer(AssetDescriptor const & descriptor) {
        for (auto & serializer : serializers_) {
            if (serializer->CanSerialize(descriptor)
                || serializer->CanDeserialize(descriptor)) {
                return serializer.get();
            }
        }
        return nullptr;
    }

}
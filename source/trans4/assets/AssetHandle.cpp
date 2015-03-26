/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "assets/AssetHandle.hpp"

namespace rpgtoolkit {
    
    AssetDescriptor const &
    AssetHandle::GetDescriptor() const {
        return descriptor_;
    }

    void
    AssetHandle::SetAsset(unique_ptr<Asset> asset) {
        asset_ = std::move(asset);
    }

    Asset *
    AssetHandle::GetAsset() const {
        return asset_.get();
    }

}
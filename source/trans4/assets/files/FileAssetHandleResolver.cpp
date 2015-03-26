/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "assets/files/FileAssetHandleResolver.hpp"

namespace rpgtoolkit {

    bool
    FileAssetHandleResolver::IsResolvable(AssetDescriptor const & descriptor) {
        return (descriptor.GetScheme() == "file");
    }

    unique_ptr<AssetHandle>
    FileAssetHandleResolver::Resolve(AssetDescriptor const & descriptor) {
        if (IsResolvable(descriptor)) {
            return unique_ptr<FileAssetHandle>(
                new FileAssetHandle(descriptor));
        }
        return nullptr;
    }

}
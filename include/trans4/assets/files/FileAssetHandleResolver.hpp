/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_FILEASSETHANDLERESOLVER_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_FILEASSETHANDLERESOLVER_INCLUDED

#include <trans4/assets/AssetHandleResolver.hpp>
#include <trans4/assets/files/FileAssetHandle.hpp>

namespace rpgtoolkit {

    struct FileAssetHandleResolver : public AssetHandleResolver {

        bool
        resolvable(AssetDescriptor const & descriptor) {
            return (descriptor.scheme() == "file");
        }

        unique_ptr<AssetHandle>
        resolve(AssetDescriptor const & descriptor) {
            if (resolvable(descriptor)) {
                return unique_ptr<FileAssetHandle>(
                        new FileAssetHandle(descriptor));
            }
            return nullptr;
        }

    };

}

#endif
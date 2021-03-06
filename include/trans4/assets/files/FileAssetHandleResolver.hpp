/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_FILEASSETHANDLERESOLVER_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_FILEASSETHANDLERESOLVER_INCLUDED

#include "assets/AssetHandleResolver.hpp"
#include "assets/files/FileAssetHandle.hpp"

namespace rpgtoolkit {

    struct FileAssetHandleResolver : public AssetHandleResolver {

        bool
        IsResolvable(AssetDescriptor const & descriptor) override;

        unique_ptr<AssetHandle>
        Resolve(AssetDescriptor const & descriptor) override;

    };

}

#endif
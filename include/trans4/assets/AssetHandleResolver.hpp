/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_ASSETHANDLERESOLVER_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_ASSETHANDLERESOLVER_INCLUDED

#include <memory>
#include <trans4/assets/AssetHandle.hpp>
#include <trans4/assets/AssetDescriptor.hpp>

namespace rpgtoolkit {

    using std::unique_ptr;

    /// Resolves an asset descriptor into an asset handle that can
    /// be used to query, read, and write asset contents.

    struct AssetHandleResolver {

        /// Determines if the asset descriptor can be resolved into
        /// an asset handle by this resolver.

        virtual bool
        resolvable(AssetDescriptor const & descriptor) = 0;

        /// Resolves an asset descriptor into an asset handle.
        ///
        /// This method may return null if the descriptor could not
        /// be resolved or the specified asset does not exist.

        virtual unique_ptr<AssetHandle>
        resolve(AssetDescriptor const & descriptor) = 0;

    };

}

#endif
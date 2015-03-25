/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_ASSETHANDLE_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_ASSETHANDLE_INCLUDED

#include <memory>
#include <iostream>

#include "assets/Asset.hpp"
#include "assets/AssetDescriptor.hpp"
#include "assets/AssetHandle.hpp"

namespace rpgtoolkit {

    using std::unique_ptr;
    using std::ostream;
    using std::istream;

    /// Handle to an asset that matches an asset descriptor to
    /// asset content and provides an abstract interface for
    /// querying asset metadata, existence, size, and other
    /// identifying information.

    struct AssetHandle {

        AssetHandle(AssetDescriptor const & descriptor)
                : descriptor_(descriptor) { }

        /// Returns descriptor associated with the asset handle

        AssetDescriptor const &
        GetDescriptor() const {
            return descriptor_;
        }

        /// Returns asset content associated with the handle.
        ///
        /// This method may return null.

        Asset *
        GetAsset() const {
            return asset_.get();
        }

        /// Sets the asset content associated with the handle.
        ///
        /// The handle will take ownership of the asset content.
        ///
        /// @param asset asset content

        void
        SetAsset(unique_ptr<Asset> asset) {
            asset_ = std::move(asset);
        }

        /// Determines if the asset content exists for the serialization
        /// method represented by the handle (e.g. file, network stream).

        virtual bool
        Exists() const = 0;

        /// Determines the total size (in bytes) of the asset content
        /// for the serialization method represented by the handle.

        virtual uintmax_t
        GetSize() const = 0;

        /// Returns a writable stream to the asset content.
        ///
        /// This method may return null if the asset contents are not
        /// writable or otherwise accessible through the asset handle.

        virtual unique_ptr<ostream>
        GetOutputStream() = 0;

        /// Returns a read-only stream of the asset content.
        ///
        /// This method may return null if the asset contents are not
        /// readable or otherwise accessible through the asset handle.

        virtual unique_ptr<istream>
        GetInputStream() = 0;

    protected:

        AssetDescriptor const & descriptor_;

        unique_ptr<Asset> asset_;

    };

}

#endif
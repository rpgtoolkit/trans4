/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_ASSETSERIALIZER_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_ASSETSERIALIZER_INCLUDED

#include "assets/AssetHandle.hpp"

namespace rpgtoolkit {

    /// Encapsulates serialization for asset contents.
    ///
    /// This class is used by the asset framework for reading
    /// and writing engine assets at runtime.

    struct AssetSerializer {

        /// Determines if the asset descriptor can be serialized.

        virtual bool
        CanSerialize(AssetDescriptor const & descriptor) = 0;

        /// Determines if the asset descriptor can be deserialized.

        virtual bool
        CanDeserialize(AssetDescriptor const & descriptor) = 0;

        /// Serializes the asset contents of the specified handle.
        ///
        /// The asset contents will be stored in the URI specified by the
        /// descriptor attached to the handle.

        virtual void
        Serialize(AssetHandle & handle) = 0;

        /// Deserializes the content of the asset descriptor specified by
        /// the asset handle and stores the contents in the handle.

        virtual void
        Deserialize(AssetHandle & handle) = 0;

    };

}

#endif
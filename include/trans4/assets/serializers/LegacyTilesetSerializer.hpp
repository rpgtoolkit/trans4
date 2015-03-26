/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_SERIALIZERS_LEGACYTILESETSERIALIZER_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_SERIALIZERS_LEGACYTILESETSERIALIZER_INCLUDED

#include <iostream>
#include <fstream>

#include "clio/common/Exception.hpp"

#include "io/BinaryReader.hpp"
#include "assets/AssetSerializer.hpp"
#include "assets/Tileset.hpp"

namespace rpgtoolkit {

    /// Implements serialization of a legacy binary game manifest file format
    /// used by previous versions of the RPG Toolkit to represent a configuration
    /// and descriptor of game projects.

    struct LegacyTilesetSerializer : public AssetSerializer {

        bool
        CanSerialize(AssetDescriptor const & descriptor) override;

        bool
        CanDeserialize(AssetDescriptor const & descriptor) override;

        void
        Serialize(AssetHandle & handle) override;

        void
        Deserialize(AssetHandle & handle) override;

    };

}

#endif
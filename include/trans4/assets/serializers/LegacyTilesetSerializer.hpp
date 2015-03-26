/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_SERIALIZERS_LEGACYTILESETSERIALIZER_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_SERIALIZERS_LEGACYTILESETSERIALIZER_INCLUDED

#include <iostream>
#include <fstream>

#include "common/Exception.hpp"
#include "io/BinaryReader.hpp"
#include "assets/AssetSerializer.hpp"
#include "assets/Tileset.hpp"

namespace rpgtoolkit {

    /// Implements serialization of a legacy binary game manifest file format
    /// used by previous versions of the RPG Toolkit to represent a configuration
    /// and descriptor of game projects.

    struct LegacyTilesetSerializer : public AssetSerializer {

        bool
        CanSerialize(AssetDescriptor const & descriptor) {
            return (descriptor.GetExtension() == "tst");
        }

        bool
        CanDeserialize(AssetDescriptor const & descriptor) {
            return CanSerialize(descriptor);
        }

        void
        Serialize(AssetHandle & handle) {


        }

        void
        Deserialize(AssetHandle & handle) {

            auto stream = handle.GetInputStream();
            auto reader = BinaryReader(*stream);

            auto version = reader.ReadShortSwapped();

            if (version != 20) {
                throw clio::Exception("Invalid tileset version.");
            }

            auto count = reader.ReadShortSwapped();
            auto detail = reader.ReadShortSwapped();
            auto dimension = 32;
            auto depth = 3;

            switch (detail) {
                case 1: // 32x32 @ 24 bpp
                    dimension = 32;
                    depth = 3;
                    break;
                case 2: // 16x16 @ 24 bpp
                    dimension = 16;
                    depth = 3;
                    break;
            }

            auto asset = unique_ptr<Tileset>(new Tileset(dimension, count));
            auto length = dimension * dimension * depth;

			auto buffer = unique_ptr<char[]>(new char[length]);

            for (int i = 0; i < count; ++i) {

                stream->read(buffer.get(), length * sizeof(char));

                for (int y = 0; y < dimension; ++y) {
                    for (int x = 0; x < dimension; ++x) {

                        auto index = (x * dimension) + y;
                        auto src = depth * index;

                        uint8_t r = buffer[src + 0];
                        uint8_t g = buffer[src + 1];
                        uint8_t b = buffer[src + 2];
                        uint8_t alpha = 255;

                        if (r == 0 && g == 1 && b == 2) {
                            alpha = 0;
                        }

                        // TODO: Copy pixel data to tileset image buffer

                    }
                }

            }

            handle.SetAsset(std::move(asset));

        }

    };

}

#endif
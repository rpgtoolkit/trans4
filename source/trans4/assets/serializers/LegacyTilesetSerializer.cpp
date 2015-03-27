/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "assets/serializers/LegacyTilesetSerializer.hpp"

namespace rpgtoolkit {

    bool
    LegacyTilesetSerializer::CanSerialize(AssetDescriptor const & descriptor) {
        return (descriptor.GetExtension() == "tst");
    }

    bool
    LegacyTilesetSerializer::CanDeserialize(AssetDescriptor const & descriptor) {
        return CanSerialize(descriptor);
    }

    void
    LegacyTilesetSerializer::Serialize(AssetHandle & handle) {


    }

    void
    LegacyTilesetSerializer::Deserialize(AssetHandle & handle) {

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

        // TODO: Detect and decode isometric tilesets

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
		auto image = asset->GetImageBuffer();
        auto pitch = dimension * count;

        auto buffer = unique_ptr<char[]>(new char[length]);

        for (int i = 0; i < count; i++) {

            stream->read(buffer.get(), length);

            for (int y = 0; y < dimension; ++y) {
                for (int x = 0; x < dimension; ++x) {

                    auto src = (x * dimension + y) * depth;
                    auto dst = (y * pitch + x + (dimension * i)) * 4;

                    auto r = buffer[src + 0];
                    auto g = buffer[src + 1];
                    auto b = buffer[src + 2];
                    auto a = 255;

                    if (r == 0 && g == 1 && b == 2) {
                        a = 0;
                    }

                    image[dst + 3] = a;
                    image[dst + 2] = r;
                    image[dst + 1] = g;
                    image[dst + 0] = b;

                }
            }

        }


        handle.SetAsset(std::move(asset));

    }

}
#ifndef RPGTOOLKIT_TRANS4_ASSETS_SERIALIZERS_LEGACYITEMSERIALIZER_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_SERIALIZERS_LEGACYITEMSERIALIZER_INCLUDED

#include "common/Exception.h"

#include "io/BinaryReader.hpp"
#include "assets/AssetSerializer.hpp"
#include "assets/Item.hpp"

namespace rpgtoolkit {

    struct LegacyItemSerializer : public AssetSerializer {

        const int VERSION_MAJOR = 2;
        const int VERSION_MINOR = 7;

        bool
        CanSerialize(AssetDescriptor const & descriptor) override {
            return (descriptor.GetExtension() == "itm");
        }

        bool
        CanDeserialize(AssetDescriptor const & descriptor) override {
            return CanSerialize(descriptor);
        }

        void
        Serialize(AssetHandle & handle) override {

        }

        virtual void
        Deserialize(AssetHandle & handle) override {

            std::unique_ptr<Item> asset(new Item());

            auto stream = handle.GetInputStream();
            auto reader = BinaryReader(*stream);

            auto header = reader.ReadString();
            auto major = reader.ReadUnsignedShortSwapped();
            auto minor = reader.ReadUnsignedShortSwapped();

            if (header != "RPGTLKIT ITEM") {
                throw clio::Exception("Unrecognized file format!");
            }

            if (!major == VERSION_MAJOR && minor == VERSION_MINOR) {
                throw clio::Exception("Unrecognized file version!");
            }

            auto name = reader.ReadString();
            auto description = reader.ReadString();

            asset->SetName(name);
            asset->SetDescription(description);

            handle.SetAsset(std::move(asset));

        }

    };

}

#endif
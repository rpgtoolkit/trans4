#ifndef RPGTOOLKIT_TRANS4_ASSETS_SERIALIZERS_LEGACYITEMSERIALIZER_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_SERIALIZERS_LEGACYITEMSERIALIZER_INCLUDED

#include "io/BinaryReader.hpp"
#include "assets/AssetSerializer.hpp"
#include "assets/Item.hpp"

namespace rpgtoolkit {

    struct LegacyItemSerializer : public AssetSerializer {

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

            string header;
            uint16_t version_major;
            uint16_t version_minor;

            reader >> header;
            reader >> version_major;
            reader >> version_minor;

            reader >> asset->name;
            reader >> asset->description;

            handle.SetAsset(std::move(asset));

        }

    };

}

#endif
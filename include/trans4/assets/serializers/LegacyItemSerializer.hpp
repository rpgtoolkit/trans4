#ifndef RPGTOOLKIT_TRANS4_ASSETS_SERIALIZERS_LEGACYITEMSERIALIZER_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_SERIALIZERS_LEGACYITEMSERIALIZER_INCLUDED

#include <trans4/io/BinaryReader.hpp>
#include <trans4/assets/AssetSerializer.hpp>
#include <trans4/assets/Item.hpp>

namespace rpgtoolkit {

    struct LegacyItemSerializer : public AssetSerializer {

        bool
        serializable(AssetDescriptor const & descriptor) override {
            return (descriptor.extension() == "itm");
        }

        bool
        deserializable(AssetDescriptor const & descriptor) override {
            return serializable(descriptor);
        }

        void
        serialize(AssetHandle & handle) override {

        }

        virtual void
        deserialize(AssetHandle & handle) override {

            std::unique_ptr<Item> asset(new Item());

            auto stream = handle.read();
            auto reader = BinaryReader(*stream);

            string header;
            uint16_t version_major;
            uint16_t version_minor;

            reader >> header;
            reader >> version_major;
            reader >> version_minor;

            reader >> asset->name;
            reader >> asset->description;

            handle.asset(std::move(asset));

        }

    };

}

#endif
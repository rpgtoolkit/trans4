/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "clio/common/Exception.hpp"

#include "assets/serializers/LegacyItemSerializer.hpp"
#include "assets/Item.hpp"
#include "io/BinaryReader.hpp"

namespace rpgtoolkit {

    bool
    LegacyItemSerializer::CanSerialize(AssetDescriptor const & descriptor) {
        return (descriptor.GetExtension() == "itm");
    }

    bool
    LegacyItemSerializer::CanDeserialize(AssetDescriptor const & descriptor) {
        return CanSerialize(descriptor);
    }

    void
    LegacyItemSerializer::Serialize(AssetHandle & handle) {

    }

    void
    LegacyItemSerializer::Deserialize(AssetHandle & handle) {

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

}
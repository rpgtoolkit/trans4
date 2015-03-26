/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "assets/serializers/LegacyGameManifestSerializer.hpp"

namespace rpgtoolkit {

    bool
    LegacyGameManifestSerializer::CanSerialize(AssetDescriptor const & descriptor) {
        return (descriptor.GetExtension() == "gam");
    }

    bool
    LegacyGameManifestSerializer::CanDeserialize(AssetDescriptor const & descriptor) {
        return CanSerialize(descriptor);
    }

    void
    LegacyGameManifestSerializer::Serialize(AssetHandle & handle) {


    }

    void
    LegacyGameManifestSerializer::Deserialize(AssetHandle & handle) {

        unique_ptr<GameManifest> asset(new GameManifest());

        auto stream = handle.GetInputStream();
        auto reader = BinaryReader(*stream);

        auto header = reader.ReadString();
        auto major = reader.ReadUnsignedShortSwapped();
        auto minor = reader.ReadUnsignedShortSwapped();

        if (header != "RPGTLKIT MAIN") {
            throw clio::Exception("Unrecognized file format!");
        }

        if (!(major = 2 && minor == 9)) {
            throw clio::Exception("Unrecognized file version!");
        }

        reader.ReadUnsignedIntegerSwapped();    // unused
        reader.ReadString();                    // unused
        reader.ReadString();                    // unused

        auto title = reader.ReadString();

        reader.ReadUnsignedShortSwapped();      // unusued

        auto fullscreen = reader.ReadUnsignedShortSwapped();
        auto resolution = reader.ReadUnsignedShortSwapped();

        reader.ReadUnsignedShortSwapped();      // unusued
        reader.ReadString();                    // unused

        auto initialProgram = reader.ReadString();
        auto initialBoard = reader.ReadString();
        auto initialCharacter = reader.ReadString();

        // Populate manifest

        asset->SetTitle(title);
        asset->SetInitialProgram(AssetDescriptor(0x00, initialProgram));
        asset->SetInitialBoard(AssetDescriptor(0x00, initialBoard));
        asset->SetInitialCharacter(AssetDescriptor(0x00, initialCharacter));

        switch (fullscreen) {
            case 1:
                asset->SetDisplayMode(DisplayMode::FULLSCREEN);
                break;
            default:
                asset->SetDisplayMode(DisplayMode::WINDOWED);
                break;
        }

        switch (resolution) {
            case 0:
                asset->SetResolutionWidth(640);
                asset->SetResolutionHeight(480);
                break;
            case 1:
                asset->SetResolutionWidth(800);
                asset->SetResolutionHeight(600);
                break;
            case 2:
                asset->SetResolutionWidth(1024);
                asset->SetResolutionHeight(768);
                break;
            default:
                throw clio::Exception(
                    "Unreognized preset screen resolution discovered");
        }

        handle.SetAsset(std::move(asset));

    }

}
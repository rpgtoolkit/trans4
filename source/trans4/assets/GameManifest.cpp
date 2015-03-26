/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "assets/GameManifest.hpp"

namespace rpgtoolkit {

    string const &
    GameManifest::GetPath() const {
        return path_;
    }

    void
    GameManifest::SetPath(string const & value) {
        path_ = value;
    }

    string const &
    GameManifest::GetTitle() const {
        return title_;
    }

    void
    GameManifest::SetTitle(string const & value) {
        title_ = value;
    }

    AssetDescriptor const &
    GameManifest::GetInitialProgram() const {
        return initialProgram_;
    }

    void
    GameManifest::SetInitialProgram(AssetDescriptor const & value) {
        initialProgram_ = value;
    }

    AssetDescriptor const &
    GameManifest::GetInitialBoard() const {
        return initialBoard_;
    }

    void
    GameManifest::SetInitialBoard(AssetDescriptor const & value) {
        initialBoard_ = value;
    }

    AssetDescriptor const &
    GameManifest::GetInitialCharacter() const {
        return initialCharacter_;
    }

    void
    GameManifest::SetInitialCharacter(AssetDescriptor const & value) {
        initialCharacter_ = value;
    }

    MovementType
    GameManifest::GetMovementType() const {
        return movementType_;
    }

    void
    GameManifest::SetMovementType(MovementType type) {
        movementType_ = type;
    }

    MovementControlFlags
    GameManifest::GetMovementControlFlags() const {
        return movementControlFlags_;
    }

    void
    GameManifest::SetMovementControlFlags(MovementControlFlags value) {
        movementControlFlags_ = value;
    }

    unsigned
    GameManifest::GetResolutionWidth() const {
        return resolutionWidth_;
    }

    void
    GameManifest::SetResolutionWidth(unsigned value) {
        resolutionWidth_ = value;
    }

    unsigned
    GameManifest::GetResolutionHeight() const {
        return resolutionHeight_;
    }

    void
    GameManifest::SetResolutionHeight(unsigned value) {
        resolutionHeight_ = value;
    }

    unsigned
    GameManifest::GetGameSpeed() const {
        return speed_;
    }

    void
    GameManifest::SetGameSpeed(unsigned value) {
        speed_ = value;
    }

    DisplayMode
    GameManifest::GetDisplayMode() const {
        return displayMode_;
    }

    void
    GameManifest::SetDisplayMode(DisplayMode value) {
        displayMode_ = value;
    }

    vector<string> &
    GameManifest::GetPlugins() {
        return plugins_;
    }

}
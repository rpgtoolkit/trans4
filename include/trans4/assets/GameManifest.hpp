#ifndef RPGTOOLKIT_TRANS4_ASSETS_GAMEMANIFEST_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_GAMEMANIFEST_INCLUDED

#include <vector>
#include <string>

#include "assets/Asset.hpp"
#include "AssetDescriptor.hpp"

namespace rpgtoolkit {

    using std::vector;
    using std::string;

    /// Possible display modes.

    enum class DisplayMode : int {
        WINDOWED,
        BORDERLESS,
        FULLSCREEN
    };


    /// Movement type (discrete or absolute); analogous to
    /// tile movement vs. pixel movement.

    enum class MovementType : int {
        DISCRETE = 0,
        ABSOLUTE = 1
    };

    /// Allowed movement controls as a set of flags. Controls
    /// which input mechanisms and styles are allowed by
    /// the engine.

    enum class MovementControlFlags : int {
        KEYS = 1,
        MOUSE = 2,
        DIAGANOLS = 4
    };

    /// Represents a description and configuration of an
    /// RPG Toolkit game project.  This manifest is used by
    /// the engine to setup the rendering state, audio system,
    /// input mappings, and other configuration tasks.

    struct GameManifest : public Asset {

        string const &
        GetPath() const {
            return path_;
        }

        void
        SetPath(string const & value) {
            path_ = value;
        }

        string const &
        GetTitle() const {
            return title_;
        }

        void
        SetTitle(string const & value) {
            title_ = value;
        }

        AssetDescriptor const &
        GetInitialProgram() const {
            return initialProgram_;
        }

        void
        SetInitialProgram(AssetDescriptor const & value) {
            initialProgram_ = value;
        }

        AssetDescriptor const &
        GetInitialBoard() const {
            return initialBoard_;
        }

        void
        SetInitialBoard(AssetDescriptor const & value) {
            initialBoard_ = value;
        }

        AssetDescriptor const &
        GetInitialCharacter() const {
            return initialCharacter_;
        }

        void
        SetInitialCharacter(AssetDescriptor const & value) {
            initialCharacter_ = value;
        }

        MovementType
        GetMovementType() const {
            return movementType_;
        }

        void
        SetMovementType(MovementType type) {
            movementType_ = type;
        }

        MovementControlFlags
        GetMovementControlFlags() const {
            return movementControlFlags_;
        }

        void
        SetMovementControlFlags(MovementControlFlags value) {
            movementControlFlags_ = value;
        }

        unsigned
        GetResolutionWidth() const {
            return resolutionWidth_;
        }

        void
        SetResolutionWidth(unsigned value) {
            resolutionWidth_ = value;
        }

        unsigned
        GetResolutionHeight() const {
            return resolutionHeight_;
        }

        void
        SetResolutionHeight(unsigned value) {
            resolutionHeight_ = value;
        }

        unsigned
        GetGameSpeed() const {
            return speed_;
        }

        void
        SetGameSpeed(unsigned value) {
            speed_ = value;
        }

        DisplayMode
        GetDisplayMode() const {
            return displayMode_;
        }

        void
        SetDisplayMode(DisplayMode value) {
            displayMode_ = value;
        }

        vector<string> &
        GetPlugins() {
            return plugins_;
        }

    private:

        vector<string> plugins_;

        string path_;

        string title_;

        unsigned resolutionWidth_;

        unsigned resolutionHeight_;

        unsigned speed_;

        AssetDescriptor initialProgram_;

        AssetDescriptor initialBoard_;

        AssetDescriptor initialCharacter_;

        MovementType movementType_;

        MovementControlFlags movementControlFlags_;

        DisplayMode displayMode_;

    };

}

#endif
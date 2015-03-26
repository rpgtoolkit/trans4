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
        GetPath() const;

        void
        SetPath(string const & value);

        string const &
        GetTitle() const;

        void
        SetTitle(string const & value);

        AssetDescriptor const &
        GetInitialProgram() const;

        void
        SetInitialProgram(AssetDescriptor const & value);

        AssetDescriptor const &
        GetInitialBoard() const;

        void
        SetInitialBoard(AssetDescriptor const & value);

        AssetDescriptor const &
        GetInitialCharacter() const;

        void
        SetInitialCharacter(AssetDescriptor const & value);

        MovementType
        GetMovementType() const;

        void
        SetMovementType(MovementType type);

        MovementControlFlags
        GetMovementControlFlags() const;

        void
        SetMovementControlFlags(MovementControlFlags value);

        unsigned
        GetResolutionWidth() const;

        void
        SetResolutionWidth(unsigned value);

        unsigned
        GetResolutionHeight() const;

        void
        SetResolutionHeight(unsigned value);

        unsigned
        GetGameSpeed() const;

        void
        SetGameSpeed(unsigned value);

        DisplayMode
        GetDisplayMode() const;

        void
        SetDisplayMode(DisplayMode value);

        vector<string> &
        GetPlugins();

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
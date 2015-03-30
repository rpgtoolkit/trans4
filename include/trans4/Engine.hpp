/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ENGINE_INCLUDED
#define RPGTOOLKIT_TRANS4_ENGINE_INCLUDED

#include <memory>

#include "clio/system/System.hpp"
#include "clio/system/SystemSettings.hpp"
#include "clio/window/Window.hpp"
#include "clio/common/Logger.hpp"
#include "clio/graphics/Texture.hpp"
#include "clio/graphics/Renderer2D.hpp"

#include "Version.hpp"
#include "game/Game.hpp"
#include "assets/AssetRepository.hpp"
#include "assets/serializers/LegacyGameManifestSerializer.hpp"
#include "assets/serializers/LegacyTilesetSerializer.hpp"
#include "assets/files/FileAssetHandleResolver.hpp"
#include "scripts/ScriptEngine.hpp"
#include "scripts/LuaScriptEngine.hpp"

namespace rpgtoolkit {

    using std::unique_ptr;
    using std::string;

    struct Engine {

        static Engine & GetInstance();

        void
        Configure();

        void
        Run();

        ScriptEngine &
        GetScriptEngine();

        AssetRepository &
        GetAssets();

        clio::Logger
        GetLog();

        Game &
        GetGame();

        Version const &
        GetVersion() const;

    private:

        unique_ptr<clio::System> system_;

        clio::Logger log_;

        AssetRepository assets_;

        LuaScriptEngine scripting_;

        Game game_;

        Engine(Engine const & rhs) = delete;

        Engine();

    };

}

#endif
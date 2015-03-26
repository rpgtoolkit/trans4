#ifndef RPGTOOLKIT_TRANS4_ENGINE_INCLUDED
#define RPGTOOLKIT_TRANS4_ENGINE_INCLUDED

#include <memory>

#include "clio/system/System.hpp"
#include "clio/system/SystemSettings.hpp"
#include "clio/window/Window.hpp"
#include "clio/common/Logger.hpp"

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

        const char * DEFAULT_LOG_FILENAME = "trans4.log";
        const char * DEFAULT_SCRIPT_FILENAME = "main.lua";

        static Engine & GetInstance() {

            static Engine instance;
            return instance;

        }

        void
        Configure() {

            clio::SystemSettings settings;

            // Configure default system settings

            settings.window.x = settings.window.POSITION_CENTERED;
            settings.window.y = settings.window.POSITION_CENTERED;
            settings.window.width = 640;
            settings.window.height = 480;
            settings.window.init_flags = 0;

            // Look for a game manifest in the current working directory
            // and load settings from this file.

            auto manifest = assets_.Load<GameManifest>("file://main.gam");

            if (manifest) {

                settings.window.width = manifest->GetResolutionWidth();
                settings.window.height = manifest->GetResolutionHeight();

                switch (manifest->GetDisplayMode()) {
                    case DisplayMode::FULLSCREEN:
                        settings.window.init_flags |= settings.window.FULLSCREEN;
                        break;
                    case DisplayMode::BORDERLESS:
                        settings.window.init_flags |= settings.window.BORDERLESS;
                        break;
                    default:
                        break;
                }

            }

            system_->Initialize(settings);

            system_->GetWindow()->SetTitle(
                manifest ? manifest->GetTitle() : "RPG Toolkit 4.0");

        }

        void
        Run() {

            LOG(&log_, "RPG Toolkit %s", GetVersion().ToString().c_str());

            scripting_.Run(DEFAULT_SCRIPT_FILENAME);
            game_.Run();

        }

        ScriptEngine &
        GetScriptEngine() {

            return scripting_;

        }

        AssetRepository &
        GetAssets() {

            return assets_;

        }

        clio::Logger
        GetLog() {

            return log_;

        }

        Game &
        GetGame() {

            return game_;

        }

        Version const &
        GetVersion() const {

            static Version v(
                RPGTOOLKIT_VERSION_MAJOR,
                RPGTOOLKIT_VERSION_MINOR,
                RPGTOOLKIT_VERSION_PATCH,
                RPGTOOLKIT_VERSION_RELEASE,
                RPGTOOLKIT_VERSION_METADATA);

            return v;

        }

    private:

        unique_ptr<clio::System> system_;

        clio::Logger log_;

        AssetRepository assets_;

        LuaScriptEngine scripting_;

        Game game_;

        Engine(Engine const & rhs) = delete;

        Engine()
            : system_(new clio::System()),
              log_(DEFAULT_LOG_FILENAME),
              game_(system_.get()) {

            // Initialize the scripting runtime

            scripting_.Initialize(&game_, system_.get());

            // Initialize supported repository resolvers and serializers

            assets_.RegisterSerializer<LegacyGameManifestSerializer>();
            assets_.RegisterSerializer<LegacyTilesetSerializer>();
            assets_.RegisterResolver<FileAssetHandleResolver>();

        }

    };

}

#endif
/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "Engine.hpp"
#include "EngineVersion.hpp"

namespace rpgtoolkit {

    const char *DEFAULT_LOG_FILENAME = "trans4.log";
    const char *DEFAULT_SCRIPT_FILENAME = "main.lua";

    Engine &
    Engine::GetInstance() {
        static Engine instance;
        return instance;
    }

    Engine::Engine()
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

    void
    Engine::Configure() {

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
    Engine::Run() {

        LOG(&log_, "RPG Toolkit %s", GetVersion().ToString().c_str());

        scripting_.Run(DEFAULT_SCRIPT_FILENAME);
        game_.Run();

    }

    ScriptEngine &
    Engine::GetScriptEngine() {

        return scripting_;

    }

    AssetRepository &
    Engine::GetAssets() {

        return assets_;

    }

    clio::Logger
    Engine::GetLog() {

        return log_;

    }

    Game &
    Engine::GetGame() {

        return game_;

    }

    Version const &
    Engine::GetVersion() const {

        static Version v(
                VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH,
                VERSION_RELEASE, VERSION_METADATA);

        return v;

    }


}
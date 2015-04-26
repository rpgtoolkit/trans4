/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "Engine.hpp"
#include "EngineVersion.hpp"
#include "common/Exception.hpp"

namespace rpgtoolkit {

    const char *DEFAULT_LOG_FILENAME = "trans4.log";
    const char *DEFAULT_SCRIPT_FILENAME = "main.lua";

    Engine &
    Engine::GetInstance() {
        static Engine instance;
        return instance;
    }

    Engine::Engine() : log_(DEFAULT_LOG_FILENAME) {

        // Initialize supported repository resolvers and serializers
        assets_.RegisterSerializer<LegacyGameManifestSerializer>();
        assets_.RegisterSerializer<LegacyTilesetSerializer>();
        assets_.RegisterResolver<FileAssetHandleResolver>();

    }

    void
    Engine::Configure(Settings const & settings) {
        // Configure default system settings
		int x = SDL_WINDOWPOS_CENTERED;
		int y = SDL_WINDOWPOS_CENTERED;
		int w, h;
		Uint32 flags = 0;
		std::string title;

        // Look for a game manifest in the current working directory
        // and load settings from this file.
        auto manifest = assets_.Load<GameManifest>("file://main.gam");
        if (manifest) {
            w = manifest->GetResolutionWidth();
            h = manifest->GetResolutionHeight();
			title = manifest->GetTitle();

            switch (manifest->GetDisplayMode()) {
                case DisplayMode::FULLSCREEN:
					flags |= SDL_WINDOW_FULLSCREEN;
                    break;
                case DisplayMode::BORDERLESS:
					flags |= SDL_WINDOW_BORDERLESS;
                    break;
                default:
                    break;
            }			
		} else{
			w = settings.window.width;
			h = settings.window.height;
			title = settings.window.title;

			if (settings.window.fullscreen) {
				//flags |= SDL_WINDOW_FULLSCREEN;
			}
		}
		
		SDL_Window* window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
		if (window == nullptr) {
			throw Exception(SDL_GetError());
		}
		window_.reset(window);

		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr) {
			throw Exception(SDL_GetError());
		}
		renderer_.reset(renderer);
		SDL_RenderSetLogicalSize(renderer, settings.game.width, settings.game.height);

    }

    void
	Engine::Run(std::string const & startup_file) {
        LOG(&log_, "RPG Toolkit %s", GetVersion().ToString().c_str());

		scripting_.Run(startup_file);
    }

	SDL_Window & 
	Engine::GetWindow() {
		return *window_.get();
	}

	SDL_Renderer &
	Engine::GetRenderer() {
		return *renderer_.get();
	}

    ScriptEngine &
    Engine::GetScriptEngine() {

        return scripting_;

    }

    AssetRepository &
    Engine::GetAssets() {

        return assets_;

    }

    Logger &
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
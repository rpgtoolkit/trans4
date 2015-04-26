/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ENGINE_INCLUDED
#define RPGTOOLKIT_TRANS4_ENGINE_INCLUDED

#include <SDL.h>
#include <memory>

#include "Version.hpp"
#include "Settings.hpp"
#include "common/Logger.hpp"
#include "game/Game.hpp"
#include "assets/AssetRepository.hpp"
#include "assets/serializers/LegacyGameManifestSerializer.hpp"
#include "assets/serializers/LegacyTilesetSerializer.hpp"
#include "assets/files/FileAssetHandleResolver.hpp"
#include "scripts/ScriptEngine.hpp"

namespace rpgtoolkit {
    using std::unique_ptr;
    using std::string;

    struct Engine {
        static Engine & 
		GetInstance();

        void
        Configure(Settings const & settings);

        void
        Run(std::string const & startup_file);

		AssetRepository &
		GetAssets();

		Game &
		GetGame();

		Logger &
		GetLog();

		SDL_Renderer &
		GetRenderer();

        ScriptEngine &
        GetScriptEngine();

		Version const &
		GetVersion() const;

		SDL_Window &
		GetWindow();
    private:
		struct WindowDeleter {
			void operator()(SDL_Window *window) {
				if (window != nullptr) {
					SDL_DestroyWindow(window);
				}
			}
		};
		unique_ptr<SDL_Window, WindowDeleter> window_;

		struct RendererDeleter {
			void operator()(SDL_Renderer *renderer) {
				if (renderer != nullptr) {
					SDL_DestroyRenderer(renderer);
				}
			}
		};
		unique_ptr<SDL_Renderer, RendererDeleter> renderer_;

        Logger log_;

        AssetRepository assets_;

        ScriptEngine scripting_;

        Game game_;

        Engine(Engine const & rhs) = delete;

        Engine();

    };

}

#endif
/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "system/System.h"
#include "system/SystemSettings.h"
#include "game/GameStateStack.h"

#include "game/Game.hpp"
#include "scripts/ScriptEngine.hpp"

#include "assets/GameManifest.hpp"
#include "assets/AssetRepository.hpp"
#include "assets/serializers/LegacyGameManifestSerializer.hpp"
#include "assets/files/FileAssetHandleResolver.hpp"

using clio::System;
using clio::SystemSettings;

using rpgtoolkit::Game;
using rpgtoolkit::ScriptEngine;

using namespace rpgtoolkit;

int main(int argc, char* argv[]) {

	AssetRepository repo;

	repo.RegisterResolver<FileAssetHandleResolver>();
	repo.RegisterSerializer<LegacyGameManifestSerializer>();

	std::string script;

	if (argc == 2) {
		script = argv[1];
		printf("Using script: %s\n", argv[1]);
	} else {
		script = "main.lua";
		printf("Defaulting to main.lua\n");
	}

	// Define the initial settings
	//TODO: Move this to a file and parse it

	SystemSettings settings;

	settings.window.x = settings.window.POSITION_CENTERED;
	settings.window.y = settings.window.POSITION_CENTERED;
	settings.window.width = 640;
	settings.window.height = 480;
	settings.window.init_flags = 0;

	// Look for a game manifest...

	auto manifest = repo.Load<GameManifest>("file://main.gam");

	if (manifest) {

		settings.window.width = manifest->GetResolutionWidth();
		settings.window.height = manifest->GetResolutionHeight();

		switch (manifest->GetDisplayMode()) {
			case DisplayMode::WINDOWED:
				settings.window.init_flags = 0;
				break;
			case DisplayMode::FULLSCREEN:
				settings.window.init_flags = clio::WindowSettings::FULLSCREEN;
				break;
			case DisplayMode::BORDERLESS:
				settings.window.init_flags = clio::WindowSettings::BORDERLESS;
				break;
		}

	}

	System* system = new System();
	system->Initialize(settings);

	Game* game = new Game(system);

	ScriptEngine* scriptEngine = new ScriptEngine();
	scriptEngine->Initialize(game, system);
	scriptEngine->Run(script);

	game->Run();

	delete game;
	delete system;

	return 0;
}
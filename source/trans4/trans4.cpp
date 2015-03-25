/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "system/System.hpp"
#include "system/SystemSettings.hpp"
#include "game/GameStateStack.hpp"

#include "game/Game.hpp"
#include "scripts/ScriptEngine.hpp"

int main(int argc, char* argv[]) {
	std::string script;
	if (argc == 2) {
		script = argv[1];
		printf("Using script: %s\n", argv[1]);
	} else {
		script = "main.lua";
		printf("Defaulting to main.lua\n");
	}

	//Define the initial settings
	//TODO: Move this to a file and parse it
	clio::SystemSettings settings;
	settings.window.x = settings.window.POSITION_CENTERED;
	settings.window.y = settings.window.POSITION_CENTERED;
	settings.window.width = 640;
	settings.window.height = 480;
	settings.window.init_flags = 0;

	clio::System* system = new clio::System();
	system->Initialize(settings);

	rpgtoolkit::Game* game = new rpgtoolkit::Game(system);

	rpgtoolkit::ScriptEngine* scriptEngine = new rpgtoolkit::ScriptEngine();
	scriptEngine->Initialize(game, system);
	scriptEngine->Run(script);

	game->Run();

	delete game;
	delete system;

	return 0;
}
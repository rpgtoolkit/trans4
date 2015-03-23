#include <string>
#include <cstdio>

#include "common/Exception.h"
#include "game/Game.h"
#include "system/System.h"
#include "scripts/ScriptEngine.h"

using namespace tk4;

int main(int argc, char* argv[]) {
	std::string script;
	if (argc == 2) {
		script = argv[1];
		printf("Using script: %s\n", argv[1]);
	} else {
		script = "main.lua";
		printf("Defaulting to main.lua\n");
	}

	//TODO: Parse settings file here

	try {
		System* system = new System();
		system->initialize();

		Game* game = new Game(system->getInput(), system->getRenderer());
		ScriptEngine* scriptEngine = new ScriptEngine();

		scriptEngine->initialize(game, system);
		scriptEngine->run(script);
		
		game->run();

		delete game;
		delete scriptEngine;
		delete system;
	} catch (tk4::Exception e) {
		System::showErrorDialog("Trans4 Error", e.what());
	}

	return 0;
}
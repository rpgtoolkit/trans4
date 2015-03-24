/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <string>
#include <cstdio>

#include <trans4/common/Exception.hpp>
#include <trans4/game/Game.hpp>
#include <trans4/system/System.hpp>
#include <trans4/scripts/ScriptEngine.hpp>

using namespace rpgtoolkit;

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

	} catch (Exception e) {

		System::showErrorDialog("Trans4 Error", e.what());

	}

	return 0;

}

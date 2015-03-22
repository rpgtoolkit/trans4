#include "common/Exception.h"
#include "game/Game.h"
#include "system/System.h"

#include "scripts/ScriptEngine.h"

using namespace tk4;

int main(int argc, char* argv[]) {
	//TODO: Parse settings file here

	/*
	ScriptEngine* scriptEngine = new ScriptEngine();
	scriptEngine->initialize(nullptr);
	scriptEngine->run("main.lua");
	*/

	try {
		System* system = new System();
		system->initialize();

		Game* game = new Game(system->getInput(), system->getRenderer());
		game->run();
		delete game;

		delete system;
	} catch (tk4::Exception e) {
		System::showErrorDialog("Trans4 Error", e.what());
	}

	return 0;
}
#include "ScriptInterface.h"

#include "game/Game.h"
#include "system/System.h"
#include "input/Input.h"
#include "input/Keyboard.h"

using namespace tk4;

static System* iSystem;
static Game* iGame;

void wrapper::setSystemInstance(tk4::System* system) {
	iSystem = system;
}

void wrapper::setGameInstance(tk4::Game* game) {
	iGame = game;
}

bool wrapper::testMe() {
	return iSystem->isInitialized();
}

bool wrapper::isKeyDown(std::string key) {
	return iSystem->getInput()->getKeyboard()->isKeyDown(tk4::Key::A);
}
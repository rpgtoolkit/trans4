#include <map>
#include <string>

#include "ScriptInterface.h"
#include "LuaGameState.h"

#include "common/Rectangle.h"
#include "game/Game.h"
#include "graphics/Renderer.h"
#include "system/System.h"
#include "input/Input.h"
#include "input/Keyboard.h"
#include "input/Key.h"

using namespace tk4;

static lua_State* L;
static System* sys;
static Renderer* renderer;
static Game* game;

void wrapper::setLuaInstance(lua_State* lua) {
	L = lua;
}

void wrapper::setSystemInstance(tk4::System* system) {
	sys = system;
	renderer = sys->getRenderer();
}

void wrapper::setGameInstance(tk4::Game* g) {
	game = g;
}

bool wrapper::isKeyDown(std::string key) {
	return sys->getInput()->getKeyboard()
		->isKeyDown(tk4::stringToKey(key));
}

void wrapper::changeState(std::string state) {
	game->changeState(new lua::GameState(L, state));
}

void wrapper::pushState(std::string state) {
	game->pushState(new lua::GameState(L, state));
}

void wrapper::popState() {
	game->popState();
}

unsigned int wrapper::loadTexture(std::string texture_file) {
	return renderer->loadTexture(texture_file);
}

void wrapper::drawTexture(int textureId, int x, int y) {
	renderer->drawTexture(textureId, x, y);
}

void wrapper::drawClip(int textureId, int x, int y, int tx, int ty, int tw, int th) {
	tk4::Rectangle rect(tx, ty, tw, th);
	renderer->drawTexture(textureId, x, y, &rect);
}


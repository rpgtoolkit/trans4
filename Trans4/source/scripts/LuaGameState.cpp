#include "LuaGameState.h"

using namespace lua;

GameState::GameState(lua_State* L, std::string gameState) : m_luaState(luabridge::getGlobal(L, gameState.c_str())) {
}

GameState::~GameState() {
}

void GameState::initialize() {
	m_luaState["initialize"]();
}

void GameState::pause() {
	m_luaState["pause"]();
}

void GameState::resume() {
	m_luaState["resume"]();
}

tk4::InputHandler* GameState::getInputHandler() {
	return nullptr;
}

void GameState::update() {
	m_luaState["update"]();
}

void GameState::render(tk4::Renderer* renderer) {
	m_luaState["render"]();
}
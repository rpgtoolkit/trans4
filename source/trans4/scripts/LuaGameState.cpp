/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <lua.hpp>
#include <LuaBridge.h>

#include <trans4/scripts/LuaGameState.hpp>

namespace rpgtoolkit {

	LuaGameState::LuaGameState(lua_State* L, std::string gameState)
		: m_luaState(luabridge::getGlobal(L, gameState.c_str())) {
	}

	LuaGameState::~LuaGameState() {
	}

	void LuaGameState::initialize() {
		m_luaState["initialize"]();
	}

	void LuaGameState::pause() {
		m_luaState["pause"]();
	}

	void LuaGameState::resume() {
		m_luaState["resume"]();
	}

	InputHandler* LuaGameState::getInputHandler() {
		return nullptr;
	}

	void LuaGameState::update() {
		m_luaState["update"]();
	}

	void LuaGameState::render(Renderer* renderer) {
		m_luaState["render"]();
	}

}

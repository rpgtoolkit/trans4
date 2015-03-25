/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <lua.hpp>
#include <LuaBridge.h>

#include "scripts/LuaGameState.hpp"

namespace rpgtoolkit {

	LuaGameState::LuaGameState(lua_State* L, std::string gameState)
		: m_luaState(luabridge::getGlobal(L, gameState.c_str())) {
	}

	LuaGameState::~LuaGameState() {
	}

	void LuaGameState::Initialize() {
		m_luaState["initialize"]();
	}

	void LuaGameState::Pause() {
		m_luaState["pause"]();
	}

	void LuaGameState::Resume() {
		m_luaState["resume"]();
	}

	clio::InputHandler* LuaGameState::GetInputHandler() {
		return nullptr;
	}

	void LuaGameState::Update() {
		m_luaState["update"]();
	}

	void LuaGameState::Render() {
		m_luaState["render"]();
	}

}

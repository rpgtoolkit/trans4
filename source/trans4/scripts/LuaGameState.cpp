/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <lua.hpp>
#include <LuaBridge.h>

#include "scripts/LuaGameState.hpp"

namespace rpgtoolkit {

	LuaGameState::LuaGameState(lua_State* L, std::string gameState)
		: luaTable_(luabridge::getGlobal(L, gameState.c_str())) {
	}

	LuaGameState::~LuaGameState() {
	}

	void LuaGameState::Initialize() {
		luaTable_["initialize"]();
	}

	void LuaGameState::Pause() {
		luaTable_["pause"]();
	}

	void LuaGameState::Resume() {
		luaTable_["resume"]();
	}

	void LuaGameState::Update() {
		luaTable_["update"]();
	}

	void LuaGameState::Render() {
		luaTable_["render"]();
	}
}

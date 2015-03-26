/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "lua.hpp"
#include "LuaBridge.h"

#include "clio/common/Exception.hpp"
#include "scripts/LuaGameState.hpp"

namespace rpgtoolkit {

	LuaGameState::LuaGameState(lua_State* L, std::string gameState)
		: luaTable_(luabridge::getGlobal(L, gameState.c_str())) {

		if (luaTable_.isTable() == false) {
			throw clio::Exception("Tried to create a LuaGameState without a Lua table.");
		}
	}

	LuaGameState::~LuaGameState() {
	}

	void LuaGameState::Initialize() {
		input_context_->RegisterQuitCallback(std::bind(&LuaGameState::Quit, this));
		CallTableFunction("initialize");
	}

	void LuaGameState::Pause() {
		CallTableFunction("pause");
	}

	void LuaGameState::Resume() {
		CallTableFunction("resume");
	}

	void LuaGameState::Update() {
		CallTableFunction("update");
	}

	void LuaGameState::Render() {
		CallTableFunction("render");
	}

	void LuaGameState::Quit() {
		CallTableFunction("quit");
	}

	void LuaGameState::CallTableFunction(const std::string& name) {
		if (luaTable_[name].isFunction()) {
			luaTable_[name]();
		}
	}
}

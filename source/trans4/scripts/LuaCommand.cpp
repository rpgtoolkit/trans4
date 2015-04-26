#include "common/Exception.hpp"

#include "scripts/LuaCommand.hpp"

namespace rpgtoolkit {
	LuaCommand::LuaCommand(lua_State* L, const std::string& table, const std::string& function)
		: luaTable_(luabridge::getGlobal(L, table.c_str())), function_(function) {

		if (luaTable_.isTable() == false) {
			throw Exception("Tried to create a LuaCommand without a Lua table.");
		}
	}

	void LuaCommand::Execute() {
		if (luaTable_[function_].isFunction()) {
			luaTable_[function_]();
		}
	}
}
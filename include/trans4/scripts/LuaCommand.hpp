#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_LUACOMMAND_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_LUACOMMAND_INCLUDED

#include "lua.hpp"
#include "LuaBridge.h"

namespace rpgtoolkit {
	struct LuaCommand {
	public:
		LuaCommand(lua_State* L, const std::string& table, const std::string& function);

		~LuaCommand();

		void Execute();
	private:
		std::string function_;

		luabridge::LuaRef luaTable_;
	};
}

#endif
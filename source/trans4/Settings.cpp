#include "lua.hpp"
#include "LuaBridge.h"

#include "Settings.hpp"

namespace rpgtoolkit {
	void Settings::LoadFromLua(std::string const & lua_file) {
		lua_State* L = luaL_newstate();
		luaL_dofile(L, lua_file.c_str());

		using namespace luabridge;

		LuaRef settings = getGlobal(L, "settings");

		LuaRef window_settings = settings["window"];
		window.width = window_settings["width"];
		window.height = window_settings["height"];
		window.fullscreen = window_settings["fullscreen"];
		window.title = window_settings["title"].cast<std::string>();

		LuaRef game_settings = settings["game"];
		game.width = game_settings["width"];
		game.height = game_settings["height"];
		game.startup_file = game_settings["start_up"].cast<std::string>();
	}
}
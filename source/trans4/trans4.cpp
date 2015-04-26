/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <SDL.h>

//Have to include this after clio Exception
//This is a hack anyway, should rethrow luabridge exceptions as tk ones
#include "lua.hpp"
#include "LuaBridge.h"

#include "Engine.hpp"
#include "Settings.hpp"
#include "common/Exception.hpp"

int main(int argc, char* argv[]) {
	try {
		rpgtoolkit::Settings settings;
		settings.LoadFromLua("settings.lua");

		auto & engine = rpgtoolkit::Engine::GetInstance();
		engine.Configure(settings);
		engine.Run(settings.game.startup_file);
	}
	catch (rpgtoolkit::Exception e) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "TK4 Error", e.what(), nullptr);
	}
	catch (luabridge::LuaException e) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Lua Error", e.what(), nullptr);
	}

	return 0;

}
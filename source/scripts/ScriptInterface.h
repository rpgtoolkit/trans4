#pragma once

#include <string>

struct lua_State;

namespace tk4 {
	class Game;
	class System;

	namespace wrapper {
		void setLuaInstance(lua_State* lua);

		void setSystemInstance(System* system);

		void setGameInstance(Game* game);

		bool isKeyDown(std::string key);

		void pushState(std::string state);
	}
}
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

		void changeState(std::string state);

		void pushState(std::string state);

		void popState();

		unsigned int loadTexture(std::string texture_file);

		void drawTexture(int textureId, int x, int y);

		void drawClip(int textureId, int x, int y, int tx, int ty, int tw, int th);
	}
}
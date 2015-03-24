#pragma once
#include <string>

#include "lua.hpp"
#include "LuaBridge.h"

#include "game/GameState.h"

namespace lua {
	class GameState : public tk4::GameState {
	public:
		GameState(lua_State* L, std::string gameState);

		~GameState();

		void initialize();

		void pause();

		void resume();

		tk4::InputHandler* getInputHandler();

		void update();

		void render(tk4::Renderer* renderer);
	private:
		luabridge::LuaRef m_luaState;
	};
}
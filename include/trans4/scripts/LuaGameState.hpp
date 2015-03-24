/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_LUAGAMESTATE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_LUAGAMESTATE_INCLUDED

#include <string>

#include <lua.hpp>
#include <LuaBridge.h>

#include <trans4/game/GameState.hpp>

namespace rpgtoolkit {

	class LuaGameState : public GameState {
	public:

		LuaGameState(lua_State* L, std::string gameState);

		~LuaGameState();

		void initialize();

		void pause();

		void resume();

		InputHandler* getInputHandler();

		void update();

		void render(Renderer* renderer);

	private:

		luabridge::LuaRef m_luaState;

	};
}

#endif

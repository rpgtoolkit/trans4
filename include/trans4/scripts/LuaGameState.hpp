/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_LUAGAMESTATE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_LUAGAMESTATE_INCLUDED

#include <string>

#include <lua.hpp>
#include <LuaBridge.h>

#include "game/GameState.h"

namespace rpgtoolkit {

	class LuaGameState : public clio::GameState {
	public:

		LuaGameState(lua_State* L, std::string gameState);

		~LuaGameState();

		void Initialize();

		void Pause();

		void Resume();

		clio::InputHandler* GetInputHandler();

		void Update();

		void Render();

	private:
		luabridge::LuaRef m_luaState;

	};
}

#endif

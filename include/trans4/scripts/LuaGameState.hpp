/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_LUAGAMESTATE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_LUAGAMESTATE_INCLUDED

#include <string>

#include <lua.hpp>
#include <LuaBridge.h>

#include "clio/game/GameState.hpp"

namespace rpgtoolkit {

	/// \brief A GameState implementation that calls on Lua scripts.
	///
	/// Lua scripts are expected to implement the functionality of the 
	/// GameState via a table, indexed by strings labeled "initialize",
	/// "pause", "resume", "update", and "render".
	struct LuaGameState : public clio::GameState {
	public:
		/// \brief Constructor
		///
		/// \param L The lua state pointer to use
		/// \param gameState The name of the lua table to index into
		LuaGameState(lua_State* L, std::string gameState);

		~LuaGameState();

		void Initialize();

		void Pause();

		void Resume();

		void Update();

		void Render();

	private:
		luabridge::LuaRef luaTable_;
		
		void Quit();
	};
}

#endif

/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTINTERFACE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTINTERFACE_INCLUDED

#include <string>

struct lua_State;

namespace rpgtoolkit {

	class Game;
	class System;

	namespace detail {

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

#endif

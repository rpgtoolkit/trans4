/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTINTERFACE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTINTERFACE_INCLUDED

#include <string>

#include "system/System.hpp"

struct lua_State;

namespace rpgtoolkit {

	struct Game;

	namespace detail {

		void SetLuaInstance(lua_State * const lua);

		void SetSystemInstance(clio::System * const system);

		void SetGameInstance(Game * const game);

		bool IsKeyDown(std::string key);

		void ChangeState(std::string state);

		void PushState(std::string state);

		void PopState();

		unsigned int LoadTexture(std::string texture_file);

		void DrawTexture(int textureId, int x, int y);

		void DrawClip(int textureId, int x, int y, int tx, int ty, int tw, int th);
	}
}

#endif

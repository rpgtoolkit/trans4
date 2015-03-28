/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTINTERFACE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTINTERFACE_INCLUDED

#include <string>

#include "clio/system/System.hpp"

struct lua_State;

namespace clio {
	struct Texture;
	struct TextureClip;
}

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

		void QuitGame();

		clio::Texture* LoadTexture(std::string texture_file);

		void FreeTexture(clio::Texture* texture);

		void DrawTexture(clio::Texture* texture, int x, int y);

		void DrawClip(clio::Texture* tex, int x, int y, int source_x, int source_y, int width, int height);
	}
}

#endif

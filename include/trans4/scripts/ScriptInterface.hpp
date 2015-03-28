/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTINTERFACE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTINTERFACE_INCLUDED

#include <string>

#include "clio/system/System.hpp"

#include "scripts/Canvas.hpp"

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

		/// Loads a texture using the engine. We return a pointer to
		/// Lua, indicating a C++ lifetime. That is, we control when
		/// the texture is deleted.
		clio::Texture* LoadTexture(std::string texture_file);

		void FreeTexture(clio::Texture* texture);

		void DrawTexture(clio::Texture* texture, int x, int y, int w, int h);

		void DrawClip(clio::Texture* tex, int x, int y, int source_x, int source_y, int width, int height);

		void SetColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

		void DrawPixel(int x, int y);

		void DrawLine(int x1, int y1, int x2, int y2);

		void DrawRect(int x, int y, int width, int height);

		void FillRect(int x, int y, int width, int height);

		/// Creates a canvas for Lua. We return the canvas by value,
		/// so it has a Lua lifetime. Lua will garbage collect it and
		/// run its destructor.
		rpgtoolkit::Canvas CreateCanvas(size_t width, size_t height);
	}
}

#endif

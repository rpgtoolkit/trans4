/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SDL_SDLRENDERER_INCLUDED
#define RPGTOOLKIT_TRANS4_SDL_SDLRENDERER_INCLUDED

#include <map>

#include <trans4/common/Rectangle.hpp>
#include <trans4/graphics/Renderer.hpp>

struct SDL_Renderer;
struct SDL_Window;

namespace rpgtoolkit {

	class SDLRenderer : public rpgtoolkit::Renderer {
	public:

		SDLRenderer(SDL_Window* sdlWindow);

		~SDLRenderer();

		void initialize();

		void clearScreen();

		TextureID loadTexture(std::string texture_file);

		void drawTexture(TextureID textureId, int x, int y, Rectangle* clip = nullptr);

		void renderScreen();

	private:

		SDL_Rect* getSDLRect(Rectangle* rect);

		SDL_Window* m_window;

		SDL_Renderer* m_renderer;

		TextureID m_textureId;

		std::map<TextureID, SDL_Texture*> m_textures;

	};
}

#endif

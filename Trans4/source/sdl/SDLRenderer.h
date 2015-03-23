#pragma once

#include <map>

#include "common/Rectangle.h"
#include "graphics/Renderer.h"

struct SDL_Renderer;
struct SDL_Window;

namespace SDL {
	class Renderer : public tk4::Renderer {
	public:
		Renderer(SDL_Window* sdlWindow);

		~Renderer();

		void initialize();

		void clearScreen();

		tk4::TextureID loadTexture(std::string texture_file);

		void drawTexture(tk4::TextureID textureId, int x, int y, tk4::Rectangle* clip = nullptr);

		void renderScreen();
	private:
		SDL_Rect* getSDLRect(tk4::Rectangle* rect);

		SDL_Window* m_window;

		SDL_Renderer* m_renderer;

		tk4::TextureID m_textureId;

		std::map<tk4::TextureID, SDL_Texture*> m_textures;
	};
}
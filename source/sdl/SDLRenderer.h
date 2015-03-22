#pragma once

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

		void draw(int x, int y, int textureId, int clipId);

		void renderScreen();
	private:
		SDL_Window* m_window;

		SDL_Renderer* m_renderer;
	};
}
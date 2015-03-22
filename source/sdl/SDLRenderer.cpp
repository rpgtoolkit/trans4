#include <SDL.h>

#include "common/Exception.h"
#include "SDLRenderer.h"

using namespace SDL;

Renderer::Renderer(SDL_Window* sdlWindow) : m_window(sdlWindow) {
	m_renderer = nullptr;
}

Renderer::~Renderer() {
	if (m_renderer != nullptr) {
		SDL_DestroyRenderer(m_renderer);
	}
}

void Renderer::initialize() {
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	if (m_renderer == nullptr) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());

		throw tk4::Exception("Could not create renderer.");
	}
	else {
		SDL_LogInfo(SDL_LOG_CATEGORY_VIDEO, "Renderer created.");
	}
}

void Renderer::clearScreen() {
	SDL_RenderClear(m_renderer);
}

void Renderer::draw(int x, int y, int textureId, int clipId) {
}

void Renderer::renderScreen() {
	SDL_RenderPresent(m_renderer);
}
#include <SDL.h>

#include "common/Exception.h"
#include "SDLRenderer.h"

using namespace SDL;

Renderer::Renderer(SDL_Window* sdlWindow) : m_window(sdlWindow), m_textureId(0) {
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

tk4::TextureID Renderer::loadTexture(std::string texture_file) {
	SDL_Surface *surface = SDL_LoadBMP(texture_file.c_str());
	if (surface == nullptr) {
		return tk4::INVALID_TEXTURE;
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	SDL_FreeSurface(surface);
	if (texture == nullptr) {
		return tk4::INVALID_TEXTURE;
	}

	m_textureId++;
	m_textures[m_textureId] = texture;

	return m_textureId;
}

void Renderer::drawTexture(tk4::TextureID textureId, int x, int y) {
	SDL_Texture *texture = m_textures[textureId];
	if (texture == nullptr) {
		return;
	}

	SDL_Rect destination;
	destination.x = x;
	destination.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &destination.w, &destination.h);

	SDL_RenderCopy(m_renderer, m_textures[textureId], NULL, &destination);
}

void Renderer::clearScreen() {
	SDL_RenderClear(m_renderer);
}

void Renderer::renderScreen() {
	SDL_RenderPresent(m_renderer);
}
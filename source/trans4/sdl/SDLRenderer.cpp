/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <SDL.h>

#include <trans4/common/Exception.hpp>
#include <trans4/common/Rectangle.hpp>
#include <trans4/sdl/SDLRenderer.hpp>

namespace rpgtoolkit {

	SDLRenderer::SDLRenderer(SDL_Window* sdlWindow)
		: m_window(sdlWindow), m_textureId(0) {
		m_renderer = nullptr;
	}

	SDLRenderer::~SDLRenderer() {
		if (m_renderer != nullptr) {
			SDL_DestroyRenderer(m_renderer);
		}
	}

	void SDLRenderer::initialize() {
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

		if (m_renderer == nullptr) {
			SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());

			throw rpgtoolkit::Exception("Could not create renderer.");
		}
		else {
			SDL_LogInfo(SDL_LOG_CATEGORY_VIDEO, "Renderer created.");
		}
	}

	TextureID SDLRenderer::loadTexture(std::string texture_file) {
		SDL_Surface *surface = SDL_LoadBMP(texture_file.c_str());
		if (surface == nullptr) {
			return rpgtoolkit::INVALID_TEXTURE;
		}

		SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
		SDL_FreeSurface(surface);
		if (texture == nullptr) {
			return rpgtoolkit::INVALID_TEXTURE;
		}

		m_textureId++;
		m_textures[m_textureId] = texture;

		return m_textureId;
	}

	void SDLRenderer::drawTexture(TextureID textureId, int x, int y, Rectangle* clip) {
		SDL_Texture *texture = m_textures[textureId];
		if (texture == nullptr) {
			return;
		}

		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		if (clip == nullptr) {
			SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
		} else {
			dest.w = clip->width;
			dest.h = clip->height;
		}

		SDL_Rect* sdlClip = getSDLRect(clip);
		SDL_RenderCopy(m_renderer, m_textures[textureId], sdlClip, &dest);
		delete sdlClip;
	}

	void SDLRenderer::clearScreen() {
		SDL_RenderClear(m_renderer);
	}

	void SDLRenderer::renderScreen() {
		SDL_RenderPresent(m_renderer);
	}

	SDL_Rect* SDLRenderer::getSDLRect(Rectangle* rect) {
		if (rect == nullptr) {
			return nullptr;
		}

		SDL_Rect* rectangle = new SDL_Rect();

		rectangle->x = rect->x;
		rectangle->y = rect->y;
		rectangle->w = rect->width;
		rectangle->h = rect->height;

		return rectangle;
	}

}

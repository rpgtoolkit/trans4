/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <SDL.h>

#include <trans4/sdl/SDLWindow.hpp>
#include <trans4/common/Exception.hpp>

namespace rpgtoolkit {

	SDLWindow::SDLWindow() {
		m_screen = nullptr;
	}

	SDLWindow::~SDLWindow() {
		if (m_screen != nullptr) {
			SDL_DestroyWindow(m_screen);
		}
	}

	void SDLWindow::initialize() {
		m_screen = SDL_CreateWindow("RPG Toolkit 4",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			0, 0,
			SDL_WINDOW_MAXIMIZED | SDL_WINDOW_OPENGL);

		if (m_screen == nullptr) {
			SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());

			throw rpgtoolkit::Exception("Could not create window.");
		} else {
			SDL_LogInfo(SDL_LOG_CATEGORY_VIDEO, "Window created.");
		}
	}

	SDL_Window* SDLWindow::getSDLWindow() {
		return m_screen;
	}

}

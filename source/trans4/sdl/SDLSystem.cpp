/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <SDL.h>

#include <trans4/common/Exception.hpp>
#include <trans4/sdl/SDLInput.hpp>
#include <trans4/sdl/SDLRenderer.hpp>
#include <trans4/sdl/SDLWindow.hpp>
#include <trans4/system/System.hpp>

namespace rpgtoolkit {

	bool System::m_initialized = false;

	Input* System::m_input;
	Renderer* System::m_renderer;
	Window* System::m_window;

	void System::initialize() {

		auto subsystems =
			SDL_INIT_TIMER | SDL_INIT_AUDIO |
			SDL_INIT_VIDEO | SDL_INIT_JOYSTICK |
			SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS;

		if (SDL_Init(subsystems) != 0) {
			SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());
			throw rpgtoolkit::Exception("Could not initialize system.");
		} else {
			m_initialized = true;
			SDL_LogInfo(SDL_LOG_CATEGORY_SYSTEM, "SDL Initialized.");
		}

		Window* window = new SDLWindow();
		m_window = window;
		m_window->initialize();

		m_renderer = new SDLRenderer(
			dynamic_cast<SDLWindow *>(window)->getSDLWindow());
		m_renderer->initialize();

		m_input = new SDLInput();
		m_input->initialize();
	}

	bool System::isInitialized() {
		return m_initialized;
	}

	Input* System::getInput() {
		SDL_assert(m_initialized);

		return m_input;
	}

	Renderer* System::getRenderer() {
		SDL_assert(m_initialized);

		return m_renderer;
	}

	Window* System::getWindow() {
		SDL_assert(m_initialized);

		return m_window;
	}

	System::~System() {
		if (m_initialized) {
			if (m_input != nullptr) {
				delete m_input;
			}

			if (m_renderer != nullptr) {
				delete m_renderer;
			}

			if (m_window != nullptr) {
				delete m_window;
			}

			SDL_Quit();
		}
	}

	void System::showErrorDialog(std::string title, std::string message) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title.c_str(), message.c_str(), NULL);
	}
}

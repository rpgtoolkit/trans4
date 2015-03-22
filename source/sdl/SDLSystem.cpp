#include <SDL.h>

#include "common/Exception.h"
#include "SDLInput.h"
#include "SDLRenderer.h"
#include "SDLWindow.h"
#include "system/System.h"


namespace tk4 {
	bool System::m_initialized = false;
	Input* System::m_input;
	Renderer* System::m_renderer;
	Window* System::m_window;
	

	void System::initialize() {
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());
			throw tk4::Exception("Could not initialize system.");
		} else {
			m_initialized = true;
			SDL_LogInfo(SDL_LOG_CATEGORY_SYSTEM, "SDL Initialized.");
		}

		SDL::Window* window = new SDL::Window();
		m_window = window;
		m_window->initialize();

		m_renderer = new SDL::Renderer(window->getSDLWindow());
		m_renderer->initialize();

		m_input = new SDL::Input();
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

	void System::finalize() {
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
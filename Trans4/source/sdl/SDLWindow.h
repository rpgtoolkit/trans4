#pragma once
#include "system/Window.h"

struct SDL_Window;

namespace SDL {
	class Window : public tk4::Window {
	public:
		Window();

		~Window();

		void initialize();

		SDL_Window* getSDLWindow();
	private:
		SDL_Window *m_screen;
	};
}


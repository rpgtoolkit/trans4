#include <SDL.h>

#include "SDLWindow.h"
#include "common/Exception.h"

using namespace SDL;

Window::Window() {
	m_screen = nullptr;
}

Window::~Window() {
	if (m_screen != nullptr) {
		SDL_DestroyWindow(m_screen);
	}
}

void Window::initialize() {
	m_screen = SDL_CreateWindow("RPG Toolkit 4",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		0, 0,
		SDL_WINDOW_MAXIMIZED | SDL_WINDOW_OPENGL);
	
	if (m_screen == nullptr) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());

		throw tk4::Exception("Could not create window.");
	} else {
		SDL_LogInfo(SDL_LOG_CATEGORY_VIDEO, "Window created.");
	}
}

SDL_Window* Window::getSDLWindow() {
	return m_screen;
}

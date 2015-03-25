#include "common/Exception.h"
#include "SDL.h"
#include "SDLWindow.h"
#include "window/WindowSettings.h"

using namespace SDL;

Window::Window() : m_logger(new clio::Logger(clio::System::LOG)), m_screen(nullptr) {
}

Window::~Window() {
}

void Window::Initialize(clio::WindowSettings settings) {
	m_screen.reset(SDL_CreateWindow("RPG Toolkit 4", settings.x, settings.y, 
		settings.width, settings.height, settings.init_flags));

	if (m_screen == nullptr) {
		LOG(m_logger.get(), "%s", SDL_GetError());
		throw clio::Exception("Could not create window.");
	} else {
		LOG(m_logger.get(), "Window created.");
	}
}
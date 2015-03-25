#include "common/Exception.hpp"
#include "SDL.hpp"
#include "SDLWindow.hpp"
#include "window/WindowSettings.hpp"

namespace SDL {
	Window::Window() : logger_(new clio::Logger(clio::System::LOG)), screen_(nullptr) {
	}

	Window::~Window() {
	}

	void Window::Initialize(clio::WindowSettings settings) {
		screen_.reset(SDL_CreateWindow("RPG Toolkit 4", settings.x, settings.y,
			settings.width, settings.height, settings.init_flags));

		if (screen_ == nullptr) {
			LOG(logger_.get(), "%s", SDL_GetError());
			throw clio::Exception("Could not create window.");
		}
		else {
			LOG(logger_.get(), "Window created.");
		}
	}
}
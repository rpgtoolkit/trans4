#include "common/Exception.hpp"
#include "common/Logger.hpp"
#include "SDL.hpp"
#include "SDLInput.hpp"
#include "SDLRenderer2D.hpp"
#include "SDLWindow.hpp"
#include "system/System.hpp"
#include "system/SystemSettings.hpp"


namespace clio {

	const std::string System::LOG = "system.log";

	System::System() : input_(new SDL::Input()), logger_(new Logger(LOG)),
		window_(new SDL::Window()), renderer_(nullptr) {
	}

	System::~System() {
	}

	void System::Initialize(SystemSettings settings) {
		if (SDL::isInitialized() == true) {
			LOG(logger_.get(), "Attempted to initialize two System objects.");
			throw clio::Exception("Dual system initialization is not allowed.");
		}

		SDL::Initialize();
		if (SDL::isInitialized() == false) {
			LOG(logger_.get(), "%s", SDL_GetError());
			throw clio::Exception("Could not initialize SDL.");
		}
		else {
			LOG(logger_.get(), "SDL Initialized.");
		}

		window_->Initialize(settings.window);

		//Need SDL::Window's SDL_Window to create an SDL::Renderer
		SDL::Window * tempWindow = dynamic_cast<SDL::Window*>(window_.get());
		renderer_.reset(new SDL::Renderer2D(tempWindow->screen_.get()));
		renderer_->Initialize();
	}

	bool System::isInitialized() {
		return SDL::isInitialized();
	}

	Window* System::GetWindow() {
		return window_.get();
	}

	Input* System::GetInput() {
		return input_.get();
	}

	Renderer2D* System::GetRenderer() {
		return renderer_.get();
	}
}
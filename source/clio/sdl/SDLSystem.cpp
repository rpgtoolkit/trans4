#include "common/Exception.h"
#include "common/Logger.h"
#include "SDL.h"
#include "SDLInput.h"
#include "SDLRenderer2D.h"
#include "SDLWindow.h"
#include "system/System.h"
#include "system/SystemSettings.h"


using namespace clio;

const std::string System::LOG = "system.log";

System::System() : m_input(new SDL::Input()), m_logger(new Logger(LOG)), 
	m_window(nullptr), m_renderer(nullptr) {
}

System::~System() {
}

void System::Initialize(SystemSettings settings) {
	if (SDL::isInitialized() == true) {
		LOG(m_logger.get(), "Attempted to initialize two System objects.");
		throw clio::Exception("Dual system initialization is not allowed.");
	}

	SDL::Initialize();
	if (SDL::isInitialized() == false) {
		LOG(m_logger.get(), "%s", SDL_GetError());
		throw clio::Exception("Could not initialize SDL.");
	} else {
		LOG(m_logger.get(), "SDL Initialized.");
	}

	SDL::Window* window = new SDL::Window();
	m_window.reset(window);
	m_window->Initialize(settings.window);

	m_renderer.reset(new SDL::Renderer2D(window->m_screen.get()));
	m_renderer->Initialize();
}

bool System::isInitialized() {
	return SDL::isInitialized();
}

Window* System::GetWindow() {
	return m_window.get();
}

Input* System::GetInput() {
	return m_input.get();
}

Renderer2D* System::GetRenderer() {
	return m_renderer.get();
}
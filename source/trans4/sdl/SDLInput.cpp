/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <SDL.h>

#include <trans4/sdl/SDLInput.hpp>
#include <trans4/sdl/SDLKeyboard.hpp>

namespace rpgtoolkit {

	SDLInput::SDLInput()
		: m_shouldQuit(false), m_keyboard(new SDLKeyboard()) {

	}

	SDLInput::~SDLInput() {
		delete m_keyboard;
	}

	void SDLInput::initialize() {
	}

	void SDLInput::process(InputHandler* handler) {
		if (handler == nullptr) {
			//ignore
		}

		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT){
				m_shouldQuit = true;
			}
		}
	}


	bool SDLInput::shouldQuit() {
		return m_shouldQuit;
	}

	Keyboard* SDLInput::getKeyboard() {
		return m_keyboard;
	}

}

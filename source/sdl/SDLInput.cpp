#include <SDL.h>

#include "SDLInput.h"
#include "SDLKeyboard.h"

using namespace SDL;

Input::Input() : m_shouldQuit(false), m_keyboard(new SDL::Keyboard()) {

}

Input::~Input() {
	delete m_keyboard;
}

void Input::initialize() {
}

void Input::process(tk4::InputHandler* handler) {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT){
			m_shouldQuit = true;
		}
	}
}


bool Input::shouldQuit() {
	return m_shouldQuit;
}

tk4::Keyboard* Input::getKeyboard() {
	return m_keyboard;
}
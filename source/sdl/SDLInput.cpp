#include <SDL.h>

#include "SDLInput.h"

using namespace SDL;

Input::Input() : m_shouldQuit(false) {

}

Input::~Input() {

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
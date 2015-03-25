#include "input/InputHandler.h"
#include "input/Key.h"
#include "SDL.h"
#include "SDLInput.h"

using namespace SDL;

Input::Input() : m_keyboard(new SDL::Keyboard()) {

}

Input::~Input() {

}

void Input::Poll(clio::InputHandler* inputHandler) {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			inputHandler->QuitRequest();
		} else if (e.type == SDL_KEYDOWN) {
			inputHandler->KeyPressed(m_keyboard->GetKey(e.key.keysym.sym));
		}
	}
}

clio::Keyboard* Input::GetKeyboard() {
	return m_keyboard.get();
}
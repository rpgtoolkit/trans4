#include "input/InputHandler.hpp"
#include "input/Key.hpp"
#include "SDL.hpp"
#include "SDLInput.hpp"

namespace SDL {
	Input::Input() : keyboard_(new SDL::Keyboard()) {
	}

	Input::~Input() {
	}

	void Input::Poll(clio::InputHandler* inputHandler) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				inputHandler->QuitRequest();
			}
			else if (e.type == SDL_KEYDOWN) {
				inputHandler->KeyPressed(keyboard_->GetKey(e.key.keysym.sym));
			}
		}
	}

	clio::Keyboard* Input::GetKeyboard() {
		return keyboard_.get();
	}
}
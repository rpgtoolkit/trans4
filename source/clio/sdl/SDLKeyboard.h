#pragma once

#include <map>

#include "SDL.h"
#include "input/Keyboard.h"

namespace SDL {
	class Keyboard : public clio::Keyboard {
	public:
		Keyboard();

		~Keyboard();

		bool isKeyDown(clio::Key key);

		clio::Key GetKey(SDL_Keycode sdlKey);
	private:
		void initKeyMappings();

		void addKeyMapping(SDL_Keycode val, clio::Key key);

		std::map<SDL_Keycode, clio::Key> m_sdlToKey;
		std::map<clio::Key, SDL_Keycode > m_keyToSdl;
	};
}
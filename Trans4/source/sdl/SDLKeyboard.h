#pragma once

#include <map>

#include "input/Keyboard.h"

namespace SDL {
	class Keyboard : public tk4::Keyboard {
	public:
		Keyboard();

		~Keyboard();

		bool isKeyDown(tk4::Key key);
	private:
		void initKeyMappings();

		void addKeyMapping(SDL_Keycode val, tk4::Key key);

		std::map<SDL_Keycode, tk4::Key> m_sdlToKey;
		std::map<tk4::Key, SDL_Keycode > m_keyToSdl;
	};
}
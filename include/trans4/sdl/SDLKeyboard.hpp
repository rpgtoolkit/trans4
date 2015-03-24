/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SDL_SDLKEYBOARD_INCLUDED
#define RPGTOOLKIT_TRANS4_SDL_SDLKEYBOARD_INCLUDED

#include <map>

#include <trans4/input/Keyboard.hpp>

namespace rpgtoolkit {

	class SDLKeyboard : public rpgtoolkit::Keyboard {
	public:

		SDLKeyboard();

		~SDLKeyboard();

		bool isKeyDown(Key key);

	private:

		void initKeyMappings();

		void addKeyMapping(SDL_Keycode val, Key key);

		std::map<SDL_Keycode, Key> m_sdlToKey;
		std::map<Key, SDL_Keycode > m_keyToSdl;

	};

}

#endif

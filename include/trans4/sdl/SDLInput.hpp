/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SDL_SDLINPUT_INCLUDED
#define RPGTOOLKIT_TRANS4_SDL_SDLINPUT_INCLUDED

#include <trans4/input/Input.hpp>
#include <trans4/input/InputHandler.hpp>

namespace rpgtoolkit {

	class SDLInput : public rpgtoolkit::Input {
	public:

		SDLInput();

		~SDLInput();

		void initialize();

		void process(InputHandler* handler);

		bool shouldQuit();

		Keyboard* getKeyboard();

	private:

		bool m_shouldQuit;

		Keyboard* m_keyboard;

	};
}

#endif

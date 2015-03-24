/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SDL_SDLWINDOW_INCLUDED
#define RPGTOOLKIT_TRANS4_SDL_SDLWINDOW_INCLUDED

#include <trans4/system/Window.hpp>

struct SDL_Window;

namespace rpgtoolkit {

	class SDLWindow : public Window {
	public:

		SDLWindow();

		~SDLWindow();

		void initialize();

		SDL_Window* getSDLWindow();

	private:

		SDL_Window *m_screen;

	};

}

#endif

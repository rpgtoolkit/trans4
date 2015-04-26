/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SETTINGS_INCLUDED
#define RPGTOOLKIT_TRANS4_SETTINGS_INCLUDED

#include <string>

namespace rpgtoolkit {
	struct WindowSettings {
	public:
		int width;
		int height;

		bool fullscreen;

		std::string title;

		WindowSettings() : width(0), height(0), fullscreen(false), title("") {}
	};

	struct GameSettings {
	public:
		int width;
		int height;

		std::string startup_file;

		GameSettings() : width(0), height(0), startup_file("") {}
	};

	struct Settings {
	public:
		WindowSettings window;
		GameSettings game;

		Settings() {}

		void LoadFromLua(std::string const & lua_file);
	};
}

#endif
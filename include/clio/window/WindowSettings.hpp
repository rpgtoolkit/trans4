#pragma once

#include <cstdint>

namespace clio {
	struct WindowSettings {
		//Various flags that can be used for the Window on initialization
		static uint32_t FULLSCREEN;
		static uint32_t FULLSCREEN_DESKTOP;
		static uint32_t BORDERLESS;
		static uint32_t RESIZABLE;
		static uint32_t MINIMIZED;
		static uint32_t MAXIMIZED;

		uint32_t init_flags;

		static int POSITION_CENTERED;
		int x;
		int y;

		int width;
		int height;
	};
}
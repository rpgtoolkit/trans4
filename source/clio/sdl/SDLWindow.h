#include <memory>

#include "common/Logger.h"
#include "system/System.h"
#include "window/Window.h"

struct SDL_Window;

namespace SDL {
	struct WindowDeleter {
		void operator()(SDL_Window* window) {
			if (window != nullptr) {
				SDL_DestroyWindow(window);
			}
		}
	};

	class Window : public clio::Window {
		friend class clio::System;
	public:
		~Window();

		/**
		* No copying allowed.
		*/
		Window(Window const&) = delete;

		/**
		* No copying allowed.
		*/
		Window & operator=(Window const&) = delete;
	protected:
		Window();

		void Initialize(clio::WindowSettings settings);

		std::unique_ptr<SDL_Window, WindowDeleter> m_screen;
	private:
		std::unique_ptr<clio::Logger> m_logger;
	};
}
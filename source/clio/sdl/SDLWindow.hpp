#include <memory>

#include "common/Logger.hpp"
#include "system/System.hpp"
#include "window/Window.hpp"

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
		
		/// No copying allowed.		
		Window(Window const&) = delete;
		
		/// No copying allowed.		
		Window & operator=(Window const&) = delete;
	protected:
		Window();

		void Initialize(clio::WindowSettings settings);

		std::unique_ptr<SDL_Window, WindowDeleter> screen_;
	private:
		std::unique_ptr<clio::Logger> logger_;
	};
}
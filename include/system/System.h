#pragma once

#include <string>

namespace tk4 {
	class Window;
	class Input;
	class Renderer;

	class System {
	public:
		System() {}

		static void initialize();

		static bool isInitialized();

		static Window* getWindow();

		static Renderer* getRenderer();

		static Input* getInput();

		static void finalize();

		static void showErrorDialog(std::string title, std::string message);
	private:
		static bool m_initialized;

		static Input* m_input;

		static Renderer* m_renderer;

		static Window* m_window;
	};
}
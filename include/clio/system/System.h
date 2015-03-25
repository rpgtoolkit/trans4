#pragma once

#include <string>
#include <memory>

namespace clio {
	class Input;
	class Logger;
	class Renderer2D;
	struct SystemSettings;
	class Window;

	class System {
	public:
		const static std::string LOG;

		/**
		* Constructor.
		*/
		System();

		/**
		* Destructor.
		*/
		~System();

		/**
		* Initialize the current system. If this has already been called on
		* another System object, an exception will be thrown.
		*/
		void Initialize(SystemSettings settings);

		/**
		* If the system has already been initialized.
		*/
		bool isInitialized();

		Window* GetWindow();

		Input* GetInput();

		Renderer2D* GetRenderer();

		/**
		* No copying allowed.
		*/
		System(System const&) = delete;

		/**
		* No copying allowed.
		*/
		System & operator=(System const&) = delete;

	private:

		std::unique_ptr<Input> m_input;

		std::unique_ptr<Logger> m_logger;

		std::unique_ptr<Renderer2D> m_renderer;

		std::unique_ptr<Window> m_window;

	};
}
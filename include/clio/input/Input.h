#pragma once

namespace clio {
	class InputHandler;
	class Keyboard;

	class Input {
		friend class System;
	public:
		/**
		* Destructor.
		*/
		virtual ~Input() {}

		/**
		* Poll the operating system for input from the user.
		*/
		virtual void Poll(InputHandler* inputHandler) = 0;

		/**
		* Get the keyboard.
		*/
		virtual Keyboard* GetKeyboard() = 0;

		/**
		* No copying allowed.
		*/
		Input(Input const&) = delete;

		/**
		* No copying allowed.
		*/
		Input & operator=(Input const&) = delete;
	protected:
		/**
		* Constructor.
		*/
		Input() {}
	};
}
#pragma once

namespace clio {
	enum class Key;

	class InputHandler {
	public:
		virtual ~InputHandler() {}

		/**
		* Called when a keyboard key is pressed.
		*
		* @param key The keyboard key that is pressed.
		*/
		virtual void KeyPressed(Key key) = 0;

		/**
		* Called when a keyboard key is released.
		*
		* @param key The keyboard key that is released.
		*/
		virtual void KeyReleased(Key key) = 0;

		/**
		* Called when the O.S. requests that the application quit.
		*/
		virtual void QuitRequest() = 0;

		/**
		* No copying allowed.
		*/
		InputHandler(InputHandler const&) = delete;

		/**
		* No copying allowed.
		*/
		InputHandler & operator=(InputHandler const&) = delete;
	protected:
		InputHandler() {}
	};
}
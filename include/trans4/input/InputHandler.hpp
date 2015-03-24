/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_INPUT_INPUTHANDLER_INCLUDED
#define RPGTOOLKIT_TRANS4_INPUT_INPUTHANDLER_INCLUDED

namespace tk4 {
	enum class Key;

	class InputHandler {
	public:
		virtual ~InputHandler() {}

		/**
		* Called when a keyboard key is pressed.
		*
		* @param key The keyboard key that is pressed.
		*/
		virtual void keyPressed(Key key) = 0;

		/**
		* Called when a keyboard key is released.
		*
		* @param key The keyboard key that is released.
		*/
		virtual void keyReleased(Key key) = 0;

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

#endif

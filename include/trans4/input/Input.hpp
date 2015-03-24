/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_INPUT_INPUT_INCLUDED
#define RPGTOOLKIT_TRANS4_INPUT_INPUT_INCLUDED

namespace rpgtoolkit {

	class InputHandler;
	class Keyboard;

	/**
	* The Input interface manages events from the user and operating system.
	*/
	class Input {
		/** Only the System class can instantiate an Input interface.*/
		friend class System;
	public:
		virtual ~Input() {}

		/**
		* Accepts input from the OS and calls the appropriate methods in
		* the given InputHandler.
		*
		* @param handler The class that handles input events.
		*/
		virtual void process(InputHandler* handler) = 0;

		/**
		* If a quit-event has been issued by the user, this will be true.
		*
		* @return true if the user wants to quit, false otherwise.
		*/
		virtual bool shouldQuit() = 0;

		/**
		* Retrieve access to the keyboard so that you can query it directly.
		*
		* @return The Keyboard implementation.
		*/
		virtual Keyboard* getKeyboard() = 0;

		/**
		* No copying allowed.
		*/
		Input(Input const&) = delete;

		/**
		* No copying allowed.
		*/
		Input & operator=(Input const&) = delete;
	protected:
		Input() {}

		virtual void initialize() = 0;
	};
}

#endif

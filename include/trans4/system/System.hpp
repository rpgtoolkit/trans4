/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SYSTEM_SYSTEM_INCLUDED
#define RPGTOOLKIT_TRANS4_SYSTEM_SYSTEM_INCLUDED

#include <string>

namespace rpgtoolkit {

	class Window;
	class Input;
	class Renderer;

	/**
	* The System interface helps with window and renderer creation, as well
	* as setting up input for a given system. Only one System can be
	* initialized at a time.
	*/
	class System {
	public:

		System() {}

		~System();

		/**
		* Initialize the current system. If this has already been called on
		* another System object, an exception will be thrown.
		*/
		static void initialize();

		/**
		* If the system has already been initialized.
		*/
		static bool isInitialized();

		/**
		* @return The created window for this system.
		*/
		static Window* getWindow();

		/**
		* @return The created renderer for this system.
		*/
		static Renderer* getRenderer();

		/**
		* @return The input manager for this system.
		*/
		static Input* getInput();

		/**
		* Show an error dialog with a given title and message to the user.
		*
		* @param title The title of the dialog
		* @param message The message displayed in the dialog
		*/
		static void showErrorDialog(std::string title, std::string message);

		/**
		* No copying allowed.
		*/
		System(System const&) = delete;

		/**
		* No copying allowed.
		*/
		System & operator=(System const&) = delete;

	private:

		static bool m_initialized;

		static Input* m_input;

		static Renderer* m_renderer;

		static Window* m_window;

	};
}

#endif

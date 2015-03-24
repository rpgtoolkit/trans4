/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SYSTEM_WINDOW_INCLUDED
#define RPGTOOLKIT_TRANS4_SYSTEM_WINDOW_INCLUDED

namespace rpgtoolkit {

	class Window {

		// Only the System class can create/destroy a window

		friend class System;

	public:

		virtual ~Window() {}

		/**
		* No copying allowed.
		*/
		Window(Window const&) = delete;

		/**
		* No copying allowed.
		*/
		Window & operator=(Window const&) = delete;

	protected:

		Window() {}

		virtual void initialize() = 0;

	};

}

#endif

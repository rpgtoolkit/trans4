#pragma once

namespace tk4 {
	class Window {
		//Only the System class can create/destroy a window	
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
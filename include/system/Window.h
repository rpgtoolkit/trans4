#pragma once

namespace tk4 {
	class Window {
		//Only the System class can create/destroy a window	
		friend class System;

	public:
		virtual ~Window() {}

		Window(Window const&) = delete;

		Window & operator=(Window const&) = delete;
	protected:
		Window() {}

		virtual void initialize() = 0;
	};
}
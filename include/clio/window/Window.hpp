#pragma once

namespace clio {
	struct WindowSettings;

	class Window {
		friend class System;
	public:
		/// Destructor.		
		virtual ~Window() {}
		
		/// No copying allowed.		
		Window(Window const&) = delete;
		
		/// No copying allowed.		
		Window & operator=(Window const&) = delete;
	protected:		
		/// Constructor.		
		Window() {}

		virtual void Initialize(WindowSettings settings) = 0;
	};
}
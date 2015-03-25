#pragma once

namespace clio {
	enum class Key;

	class InputHandler {
	public:
		virtual ~InputHandler() {}

		/// \brief Called when a keyboard key is pressed.
		///
		/// \param key The keyboard key that is pressed.
		virtual void KeyPressed(Key key) = 0;

		
		/// \brief Called when a keyboard key is released.
		///
		/// \param key The keyboard key that is released.		
		virtual void KeyReleased(Key key) = 0;

		
		/// \brief Called when the O.S. requests that the application quit.		
		virtual void QuitRequest() = 0;

		
		/// \brief No copying allowed.		
		InputHandler(InputHandler const&) = delete;

		
		/// \brief No copying allowed.		
		InputHandler & operator=(InputHandler const&) = delete;
	protected:
		/// \brief Constructor.
		InputHandler() {}
	};
}
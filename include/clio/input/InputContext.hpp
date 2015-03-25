#pragma once

#include <functional>
#include <map>

#include "InputHandler.hpp"

namespace clio {
	enum class Key;

	/// \brief The callback format for when a key is pressed.
	typedef std::function<void(bool)> KeyCallback;

	/// \brief The callback format for when quit is requested by the user.
	typedef std::function<void(void)> QuitCallback;

	class InputContext : public InputHandler {
	public:
		/// \brief Constructor.
		InputContext();

		~InputContext();

		void KeyPressed(Key key);

		void KeyReleased(Key key);

		void QuitRequest();

		void RegisterKeyCallback(Key key, KeyCallback callback);

		void RegisterQuitCallback(QuitCallback callback);
	private:
		std::map <Key, KeyCallback> key_callbacks_;

		QuitCallback quit_callback_;
	};
}
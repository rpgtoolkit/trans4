#pragma once

#include <functional>
#include <map>

#include "InputHandler.h"

namespace clio {
	enum class Key;

	typedef std::function<void(bool)> KeyCallback;

	typedef std::function<void(void)> QuitCallback;

	class InputContext : public InputHandler {
	public:
		InputContext();

		~InputContext();

		void KeyPressed(Key key);

		void KeyReleased(Key key);

		void QuitRequest();

		void RegisterKeyCallback(Key key, KeyCallback callback);

		void RegisterQuitCallback(QuitCallback callback);
	private:
		std::map <Key, KeyCallback> m_keyCallbacks;

		QuitCallback m_quitCallback;
	};
}
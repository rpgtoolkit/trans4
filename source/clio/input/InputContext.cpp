#include "input/InputContext.hpp"
#include "input/Key.hpp"

namespace clio {

	InputContext::InputContext() {

	}

	InputContext::~InputContext() {

	}

	void InputContext::KeyPressed(Key key) {
		auto exists = key_callbacks_.find(key);
		if (exists != key_callbacks_.end()) {
			exists->second(true);
		}
	}

	void InputContext::KeyReleased(Key key) {
		auto exists = key_callbacks_.find(key);
		if (exists != key_callbacks_.end()) {
			exists->second(false);
		}
	}

	void InputContext::RegisterKeyCallback(Key key, KeyCallback callback) {
		key_callbacks_.insert(std::pair<Key, KeyCallback>(key, callback));
	}

	void InputContext::RegisterQuitCallback(QuitCallback callback) {
		quit_callback_ = callback;
	}

	void InputContext::QuitRequest() {
		quit_callback_();
	}
}
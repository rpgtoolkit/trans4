#include "input/InputContext.h"
#include "input/Key.h"

using namespace clio;

InputContext::InputContext() {

}

InputContext::~InputContext() {

}

void InputContext::KeyPressed(Key key) {
	auto exists = m_keyCallbacks.find(key);
	if (exists != m_keyCallbacks.end()) {
		exists->second(true);
	}
}

void InputContext::KeyReleased(Key key) {
	auto exists = m_keyCallbacks.find(key);
	if (exists != m_keyCallbacks.end()) {
		exists->second(false);
	}
}

void InputContext::RegisterKeyCallback(Key key, KeyCallback callback) {
	m_keyCallbacks.insert(std::pair<Key, KeyCallback>(key, callback));
}

void InputContext::RegisterQuitCallback(QuitCallback callback) {
	m_quitCallback = callback;
}

void InputContext::QuitRequest() {
	m_quitCallback();
}
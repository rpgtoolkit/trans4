#include <map>

#include "input/Key.h"

using namespace tk4;

static std::map<std::string, Key> strToKey = {
	{ "UNKNOWN", Key::UNKNOWN },
	{ "A", Key::A },
	{ "B", Key::B },
	{ "C", Key::C },
	{ "D", Key::D },
	{ "E", Key::E },
	{ "F", Key::F },
	{ "G", Key::G },
	{ "H", Key::H },
	{ "I", Key::I },
	{ "J", Key::J },
	{ "K", Key::K },
	{ "L", Key::L },
	{ "M", Key::M },
	{ "N", Key::N },
	{ "O", Key::O },
	{ "P", Key::P },
	{ "Q", Key::Q },
	{ "R", Key::R },
	{ "S", Key::S },
	{ "T", Key::T },
	{ "U", Key::U },
	{ "V", Key::V },
	{ "W", Key::W },
	{ "X", Key::X },
	{ "Y", Key::Y },
	{ "Z", Key::Z },

	{ "0", Key::N0 },
	{ "1", Key::N1 },
	{ "2", Key::N2 },
	{ "3", Key::N3 },
	{ "4", Key::N4 },
	{ "5", Key::N5 },
	{ "6", Key::N6 },
	{ "7", Key::N7 },
	{ "8", Key::N8 },
	{ "9", Key::N9 },

	{ "SPACE", Key::SPACE },
	{ "ESCAPE", Key::ESC },

	{ "F1", Key::F1 },
	{ "F2", Key::F2 },
	{ "F3", Key::F3 },
	{ "F4", Key::F4 },
	{ "F5", Key::F5 },
	{ "F6", Key::F6 },
	{ "F7", Key::F7 },
	{ "F8", Key::F8 },
	{ "F9", Key::F9 },
	{ "F10", Key::F10 },
	{ "F11", Key::F11 },
	{ "F12", Key::F12 },
	{ "F13", Key::F13 },
	{ "F14", Key::F14 },
	{ "F15", Key::F15 },
	{ "F16", Key::F16 },
	{ "F17", Key::F17 },
	{ "F18", Key::F18 },
	{ "F19", Key::F19 },
	{ "F20", Key::F20 },
	{ "F21", Key::F21 },
	{ "F22", Key::F22 },
	{ "F23", Key::F23 },
	{ "F24", Key::F24 },

	{ "UP", Key::UP },
	{ "DOWN", Key::DOWN },
	{ "LEFT", Key::LEFT },
	{ "RIGHT", Key::RIGHT },
	{ "LSHIFT", Key::LSHIFT },
	{ "RSHIFT", Key::RSHIFT },
	{ "LCTRL", Key::LCTRL },
	{ "RCTRL", Key::RCTRL },
	{ "LALT", Key::LALT },
	{ "RALT", Key::RALT },
	{ "TAB", Key::TAB },
	{ "RETURN", Key::ENTER },
	{ "BACKSPACE", Key::BACKSPACE },
	{ "INSERT", Key::INSERT },
	{ "DELETE", Key::DEL },
	{ "PAGEUP", Key::PAGEUP },
	{ "PAGEDOWN", Key::PAGEDOWN },
	{ "HOME", Key::HOME },
	{ "END", Key::END },

	{ "KP_0", Key::KP_0 },
	{ "KP_1", Key::KP_1 },
	{ "KP_2", Key::KP_2 },
	{ "KP_3", Key::KP_3 },
	{ "KP_4", Key::KP_4 },
	{ "KP_5", Key::KP_5 },
	{ "KP_6", Key::KP_6 },
	{ "KP_7", Key::KP_7 },
	{ "KP_8", Key::KP_8 },
	{ "KP_9", Key::KP_9 },
	{ "KP_DIVIDE", Key::KP_DIVIDE },
	{ "KP_MULTIPLY", Key::KP_MULTIPLY },
	{ "KP_MINUS", Key::KP_SUBTRACT },
	{ "KP_PLUS", Key::KP_ADD },
	{ "KP_DECIMAL", Key::KP_DECIMAL },
	{ "KP_EQUALS", Key::KP_EQUAL },
	{ "KP_ENTER", Key::KP_ENTER },

	{ "NUMLOCKCLEAR", Key::NUM_LOCK },
	{ "CAPSLOCK", Key::CAPS_LOCK },
	{ "SCROLLLOCK", Key::SCROLL_LOCK },
	{ "PAUSE", Key::PAUSE },
	{ "MENU", Key::MENU } };

Key tk4::stringToKey(std::string str) {
	return strToKey[str];
}

std::string tk4::keyToString(Key key) {
	for (auto& sk : strToKey) {
		if (sk.second == key) {
			return sk.first;
		}
	}

	return "UNKNOWN";
}
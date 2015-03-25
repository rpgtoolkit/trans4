#pragma once

#include <string>

namespace clio {
	enum class Key;
	
	/// Converts a string to a key.
	///
	/// \param str The string to convert
	/// \return The key that corresponds to the string, or UNKNOWN.	
	Key StringToKey(const std::string& str);
	
	/// Converts a key to a string.
	///
	/// \param key The key to convert
	/// \return The string that corresponds to the key.	
	std::string KeyToString(const Key& key);
	
	/// An enumeration of the various keys that can be found on a keyboard.	
	enum class Key : int {
		UNKNOWN,

		//Numbers
		N0 = 48,
		N1,
		N2,
		N3,
		N4,
		N5,
		N6,
		N7,
		N8,
		N9,

		//Letters
		A = 65,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,

		SPACE,
		SPECIAL,
		ESC,

		//Function Keys
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		F13,
		F14,
		F15,
		F16,
		F17,
		F18,
		F19,
		F20,
		F21,
		F22,
		F23,
		F24,

		UP,
		DOWN,
		LEFT,
		RIGHT,
		LSHIFT,
		RSHIFT,
		LCTRL,
		RCTRL,
		LALT,
		RALT,
		TAB,
		ENTER,
		BACKSPACE,
		INSERT,
		DEL,
		PAGEUP,
		PAGEDOWN,
		HOME,
		END,

		//Keypad
		KP_0,
		KP_1,
		KP_2,
		KP_3,
		KP_4,
		KP_5,
		KP_6,
		KP_7,
		KP_8,
		KP_9,
		KP_DIVIDE,
		KP_MULTIPLY,
		KP_SUBTRACT,
		KP_ADD,
		KP_DECIMAL,
		KP_EQUAL,
		KP_ENTER,

		NUM_LOCK,
		CAPS_LOCK,
		SCROLL_LOCK,
		PAUSE,
		MENU
	};
}
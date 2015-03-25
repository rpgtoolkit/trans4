#include "input/Key.hpp"
#include "SDLKeyboard.hpp"


namespace SDL {

	Keyboard::Keyboard() {
		initKeyMappings();
	}

	Keyboard::~Keyboard() {

	}

	bool Keyboard::isKeyDown(clio::Key key) {
		const Uint8 *state = SDL_GetKeyboardState(nullptr);

		//Need to convert from tk4::Key to SDL Key to SDL Scancode
		SDL_Scancode scancode = SDL_GetScancodeFromKey(m_keyToSdl[key]);
		if (state[scancode] == 1) {
			return true;
		}

		return false;
	}

	clio::Key Keyboard::GetKey(SDL_Keycode sdlKey) {
		return m_sdlToKey[sdlKey];
	}

	void Keyboard::addKeyMapping(SDL_Keycode val, clio::Key key) {
		m_keyToSdl[key] = val;
		m_sdlToKey[val] = key;
	}

	void Keyboard::initKeyMappings() {
		using namespace clio;

		addKeyMapping(SDLK_UNKNOWN, Key::UNKNOWN);

		addKeyMapping(SDLK_a, Key::A);
		addKeyMapping(SDLK_b, Key::B);
		addKeyMapping(SDLK_c, Key::C);
		addKeyMapping(SDLK_d, Key::D);
		addKeyMapping(SDLK_e, Key::E);
		addKeyMapping(SDLK_f, Key::F);
		addKeyMapping(SDLK_g, Key::G);
		addKeyMapping(SDLK_h, Key::H);
		addKeyMapping(SDLK_i, Key::I);
		addKeyMapping(SDLK_j, Key::J);
		addKeyMapping(SDLK_k, Key::K);
		addKeyMapping(SDLK_l, Key::L);
		addKeyMapping(SDLK_m, Key::M);
		addKeyMapping(SDLK_n, Key::N);
		addKeyMapping(SDLK_o, Key::O);
		addKeyMapping(SDLK_p, Key::P);
		addKeyMapping(SDLK_q, Key::Q);
		addKeyMapping(SDLK_r, Key::R);
		addKeyMapping(SDLK_s, Key::S);
		addKeyMapping(SDLK_t, Key::T);
		addKeyMapping(SDLK_u, Key::U);
		addKeyMapping(SDLK_v, Key::V);
		addKeyMapping(SDLK_w, Key::W);
		addKeyMapping(SDLK_x, Key::X);
		addKeyMapping(SDLK_y, Key::Y);
		addKeyMapping(SDLK_z, Key::Z);

		addKeyMapping(SDLK_0, Key::N0);
		addKeyMapping(SDLK_1, Key::N1);
		addKeyMapping(SDLK_2, Key::N2);
		addKeyMapping(SDLK_3, Key::N3);
		addKeyMapping(SDLK_4, Key::N4);
		addKeyMapping(SDLK_5, Key::N5);
		addKeyMapping(SDLK_6, Key::N6);
		addKeyMapping(SDLK_7, Key::N7);
		addKeyMapping(SDLK_8, Key::N8);
		addKeyMapping(SDLK_9, Key::N9);

		addKeyMapping(SDLK_SPACE, Key::SPACE);
		addKeyMapping(SDLK_ESCAPE, Key::ESC);

		addKeyMapping(SDLK_F1, Key::F1);
		addKeyMapping(SDLK_F2, Key::F2);
		addKeyMapping(SDLK_F3, Key::F3);
		addKeyMapping(SDLK_F4, Key::F4);
		addKeyMapping(SDLK_F5, Key::F5);
		addKeyMapping(SDLK_F6, Key::F6);
		addKeyMapping(SDLK_F7, Key::F7);
		addKeyMapping(SDLK_F8, Key::F8);
		addKeyMapping(SDLK_F9, Key::F9);
		addKeyMapping(SDLK_F10, Key::F10);
		addKeyMapping(SDLK_F11, Key::F11);
		addKeyMapping(SDLK_F12, Key::F12);
		addKeyMapping(SDLK_F13, Key::F13);
		addKeyMapping(SDLK_F14, Key::F14);
		addKeyMapping(SDLK_F15, Key::F15);
		addKeyMapping(SDLK_F16, Key::F16);
		addKeyMapping(SDLK_F17, Key::F17);
		addKeyMapping(SDLK_F18, Key::F18);
		addKeyMapping(SDLK_F19, Key::F19);
		addKeyMapping(SDLK_F20, Key::F20);
		addKeyMapping(SDLK_F21, Key::F21);
		addKeyMapping(SDLK_F22, Key::F22);
		addKeyMapping(SDLK_F23, Key::F23);
		addKeyMapping(SDLK_F24, Key::F24);

		addKeyMapping(SDLK_UP, Key::UP);
		addKeyMapping(SDLK_DOWN, Key::DOWN);
		addKeyMapping(SDLK_LEFT, Key::LEFT);
		addKeyMapping(SDLK_RIGHT, Key::RIGHT);
		addKeyMapping(SDLK_LSHIFT, Key::LSHIFT);
		addKeyMapping(SDLK_RSHIFT, Key::RSHIFT);
		addKeyMapping(SDLK_LCTRL, Key::LCTRL);
		addKeyMapping(SDLK_RCTRL, Key::RCTRL);
		addKeyMapping(SDLK_LALT, Key::LALT);
		addKeyMapping(SDLK_RALT, Key::RALT);
		addKeyMapping(SDLK_TAB, Key::TAB);
		addKeyMapping(SDLK_RETURN, Key::ENTER);
		addKeyMapping(SDLK_BACKSPACE, Key::BACKSPACE);
		addKeyMapping(SDLK_INSERT, Key::INSERT);
		addKeyMapping(SDLK_DELETE, Key::DEL);
		addKeyMapping(SDLK_PAGEUP, Key::PAGEUP);
		addKeyMapping(SDLK_PAGEDOWN, Key::PAGEDOWN);
		addKeyMapping(SDLK_HOME, Key::HOME);
		addKeyMapping(SDLK_END, Key::END);

		addKeyMapping(SDLK_KP_0, Key::KP_0);
		addKeyMapping(SDLK_KP_1, Key::KP_1);
		addKeyMapping(SDLK_KP_2, Key::KP_2);
		addKeyMapping(SDLK_KP_3, Key::KP_3);
		addKeyMapping(SDLK_KP_4, Key::KP_4);
		addKeyMapping(SDLK_KP_5, Key::KP_5);
		addKeyMapping(SDLK_KP_6, Key::KP_6);
		addKeyMapping(SDLK_KP_7, Key::KP_7);
		addKeyMapping(SDLK_KP_8, Key::KP_8);
		addKeyMapping(SDLK_KP_9, Key::KP_9);
		addKeyMapping(SDLK_KP_DIVIDE, Key::KP_DIVIDE);
		addKeyMapping(SDLK_KP_MULTIPLY, Key::KP_MULTIPLY);
		addKeyMapping(SDLK_KP_MINUS, Key::KP_SUBTRACT);
		addKeyMapping(SDLK_KP_PLUS, Key::KP_ADD);
		addKeyMapping(SDLK_KP_DECIMAL, Key::KP_DECIMAL);
		addKeyMapping(SDLK_KP_EQUALS, Key::KP_EQUAL);
		addKeyMapping(SDLK_KP_ENTER, Key::KP_ENTER);

		addKeyMapping(SDLK_NUMLOCKCLEAR, Key::NUM_LOCK);
		addKeyMapping(SDLK_CAPSLOCK, Key::CAPS_LOCK);
		addKeyMapping(SDLK_SCROLLLOCK, Key::SCROLL_LOCK);
		addKeyMapping(SDLK_PAUSE, Key::PAUSE);
		addKeyMapping(SDLK_MENU, Key::MENU);
	}

}
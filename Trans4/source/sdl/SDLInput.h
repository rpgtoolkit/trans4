#pragma once

#include "input/Input.h"
#include "input/InputHandler.h"

namespace SDL {
	class Input : public tk4::Input {
	public:
		Input();

		~Input();

		void initialize();

		void process(tk4::InputHandler* handler);

		bool shouldQuit();

		tk4::Keyboard* getKeyboard();
	private:
		bool m_shouldQuit;

		tk4::Keyboard* m_keyboard;
	};
}
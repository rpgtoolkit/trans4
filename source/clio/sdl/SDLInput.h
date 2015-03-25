#pragma once

#include <memory>

#include "input/Input.h"
#include "SDLKeyboard.h"

namespace SDL {
	class Input : public clio::Input {
		friend class clio::System;
	public:
		~Input();

		void Poll(clio::InputHandler* inputHandler);

		clio::Keyboard* GetKeyboard();

		/**
		* No copying allowed.
		*/
		Input(Input const&) = delete;

		/**
		* No copying allowed.
		*/
		Input & operator=(Input const&) = delete;
	protected:
		Input();

		std::unique_ptr<Keyboard> m_keyboard;
	};
}
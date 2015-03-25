#pragma once

#include <memory>

#include "system/System.hpp"
#include "input/Input.hpp"
#include "SDLKeyboard.hpp"

namespace SDL {
	class Input : public clio::Input {
		friend class clio::System;
	public:
		~Input();

		void Poll(clio::InputHandler* inputHandler);

		clio::Keyboard* GetKeyboard();
		
		/// No copying allowed.		
		Input(Input const&) = delete;
		
		/// No copying allowed.		
		Input & operator=(Input const&) = delete;
	protected:
		Input();

		std::unique_ptr<Keyboard> keyboard_;
	};
}
#pragma once

namespace tk4 {
	class InputHandler;
	class Keyboard;

	class Input {
		friend class System;
	public:
		virtual ~Input() {}

		virtual void process(InputHandler* handler) = 0;

		virtual bool shouldQuit() = 0;

		virtual Keyboard* getKeyboard() = 0;

		Input(Input const&) = delete;

		Input & operator=(Input const&) = delete;
	protected:
		Input() {}

		virtual void initialize() = 0;
	};
}
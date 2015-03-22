#pragma once

namespace tk4 {
	class InputHandler;

	class Input {
		friend class System;
	public:
		virtual void process(InputHandler* handler) = 0;

		virtual bool shouldQuit() = 0;

		virtual ~Input() {}

		Input(Input const&) = delete;

		Input & operator=(Input const&) = delete;
	protected:
		Input() {}

		virtual void initialize() = 0;
	};
}
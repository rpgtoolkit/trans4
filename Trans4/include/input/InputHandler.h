#pragma once

namespace tk4 {
	enum class Key;

	class InputHandler {
	public:
		InputHandler() {}

		virtual ~InputHandler() {}

		virtual void keyPressed(Key key) {}

		virtual void keyReleased(Key key) {}

		InputHandler(InputHandler const&) = delete;

		InputHandler & operator=(InputHandler const&) = delete;
	protected:

	};
}
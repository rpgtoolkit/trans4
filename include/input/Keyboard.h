#pragma once

namespace tk4 {
	enum class Key;

	class Keyboard {
	public:
		virtual ~Keyboard() {}

		virtual bool isKeyDown(Key key) = 0;
	protected:
		Keyboard() {}
	};
}
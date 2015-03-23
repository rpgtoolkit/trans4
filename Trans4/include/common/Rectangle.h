#pragma once

namespace tk4 {
	struct Rectangle {
		int x;
		int y;
		int width;
		int height;

		explicit Rectangle(int xpos, int ypos, int w, int h) 
			: x(xpos), y(ypos), width(w), height(h) {}
	};
}
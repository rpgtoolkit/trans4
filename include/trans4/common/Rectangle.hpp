/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_COMMON_RECTANGLE_INCLUDED
#define RPGTOOLKIT_TRANS4_COMMON_RECTANGLE_INCLUDED

namespace rpgtoolkit {

	struct Rectangle {

		int x;
		int y;
		int width;
		int height;

		explicit Rectangle(int xpos, int ypos, int w, int h)
			: x(xpos), y(ypos), width(w), height(h) {}

	};

}

#endif

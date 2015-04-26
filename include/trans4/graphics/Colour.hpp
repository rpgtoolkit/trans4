/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_GRAPHICS_COLOUR_INCLUDED
#define RPGTOOLKIT_TRANS4_GRAPHICS_COLOUR_INCLUDED

#include <cstdint>

namespace rpgtoolkit {
	struct Colour {
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;

		Colour(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : red(r), green(g), blue(b), alpha(a) {}

		Colour() : red(0), green(0), blue(0), alpha(0) {}
	};

	namespace colours {
		static Colour WHITE = Colour(255, 255, 255, 0);
		static Colour BLACK = Colour(0, 0, 0, 0);
	}
}

#endif
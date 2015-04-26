/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTINTERFACE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTINTERFACE_INCLUDED

#include <string>

namespace rpgtoolkit {
	struct Colour;
	struct Settings;

	namespace detail {

		bool IsKeyDown(std::string const & key);

		void RenderDraws();

		void ClearScreen();

		void SetColour(Colour const & colour);

		void DrawPixel(int const & x, int const & y);

		void DrawLine(int const & x1, int const & y1, int const & x2, int const & y2);

		void DrawRect(int const & x, int const & y, int const & width, int const & height);

		void FillRect(int const & x, int const & y, int const & width, int const & height);
	}
}

#endif

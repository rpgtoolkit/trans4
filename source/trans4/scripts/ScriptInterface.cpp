/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <SDL.h>

#include <memory>
#include <string>

#include "Engine.hpp"
#include "Settings.hpp"
#include "graphics/Colour.hpp"
#include "scripts/ScriptInterface.hpp"

namespace rpgtoolkit {

    bool detail::IsKeyDown(std::string const & key) {
		SDL_PumpEvents();
		const Uint8 *state = SDL_GetKeyboardState(nullptr);

		return state[SDL_GetScancodeFromName(key.c_str())] == 1;
    }

	void detail::RenderDraws() {
		SDL_RenderPresent(&Engine::GetInstance().GetRenderer());
	}

	void detail::ClearScreen() {
		SDL_RenderClear(&Engine::GetInstance().GetRenderer());
	}

	void detail::SetColour(Colour const & colour) {
		SDL_SetRenderDrawColor(&Engine::GetInstance().GetRenderer(), colour.red, colour.green, colour.blue, colour.alpha);
	}

	void detail::DrawPixel(int const & x, int const & y) {
		SDL_RenderDrawPoint(&Engine::GetInstance().GetRenderer(), x, y);
	}

	void detail::DrawLine(int const & x1, int const & y1, int const & x2, int const & y2) {
		SDL_RenderDrawLine(&Engine::GetInstance().GetRenderer(), x1, y1, x2, y2);
	}

	void detail::DrawRect(int const & x, int const & y, int const & width, int const & height) {
		SDL_Rect rect;
		rect.x = x;
		rect.y = y;
		rect.w = width;
		rect.h = height;

		SDL_RenderDrawRect(&Engine::GetInstance().GetRenderer(), &rect);
	}

	void detail::FillRect(int const & x, int const & y, int const & width, int const & height) {
		SDL_Rect rect;
		rect.x = x;
		rect.y = y;
		rect.w = width;
		rect.h = height;

		SDL_RenderFillRect(&Engine::GetInstance().GetRenderer(), &rect);
	}
}

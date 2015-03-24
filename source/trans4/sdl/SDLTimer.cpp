/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <SDL.h>

#include <trans4/system/System.hpp>
#include <trans4/system/Timer.hpp>

namespace rpgtoolkit {

	Timer::Timer() {
	}

	Timer::~Timer() {
	}

	void Timer::start() {
		SDL_assert(System::isInitialized());
		m_start = SDL_GetTicks();
	}

	void Timer::reset() {
		start();
	}

	uint32_t Timer::elapsed() {
		SDL_assert(System::isInitialized());
		return SDL_GetTicks() - m_start;
	}

}

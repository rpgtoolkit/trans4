#include <SDL.h>

#include "system/System.h"
#include "system/Timer.h"

using namespace tk4;

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
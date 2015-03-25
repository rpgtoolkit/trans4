#include "SDL.hpp"

static bool sdlInitialized = false;

void SDL::Initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		sdlInitialized = false;
	} else {
		sdlInitialized = true;
	}
}

bool SDL::isInitialized() {
	return sdlInitialized;
}
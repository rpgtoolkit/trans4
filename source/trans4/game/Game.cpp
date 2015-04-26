/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <SDL.h>

#include "common/Logger.hpp"
#include "common/Timer.hpp"

#include "game/Game.hpp"
#include "Engine.hpp"

namespace rpgtoolkit {

	const std::string Game::LOG = "game.log";

	Game::Game() : log_(new Logger(LOG)), quit_(false) {
	}

	Game::~Game() {
	}

	void Game::Run() {
		LOG(log_.get(), "Game started.");

		const double SEC_PER_UPDATE = .001; //1 millisecond
		double lag = 0, elapsed;

		Timer loopTimer(true);
		while (quit_ == false) {
			elapsed = loopTimer.Reset();
			lag += elapsed;

			Poll();

			//Update several times to make up for lag.
			while (lag >= SEC_PER_UPDATE) {
				lag -= SEC_PER_UPDATE;
			}
		}
	}

	void Game::Quit() {
		quit_ = true;
	}

	void Game::Poll() {
		SDL_Event e;

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				Quit();
			}
			else if (e.type == SDL_KEYDOWN) {
			}
		}
	}
}
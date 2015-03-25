/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "common/Logger.hpp"
#include "common/Timer.hpp"
#include "game/GameState.hpp"
#include "game/GameStateStack.hpp"
#include "input/Input.hpp"
#include "system/System.hpp"

#include "game/Game.hpp"

namespace rpgtoolkit {

	const std::string Game::LOG = "game.log";

	Game::Game(clio::System* system) : log_(new clio::Logger(LOG)), quit_(false), stack_(new clio::GameStateStack()), system_(system) {
	}

	Game::~Game() {
	}

	void Game::Run() {
		LOG(log_.get(), "Game started.");

		const double SEC_PER_UPDATE = .001; //1 millisecond
		double lag = 0, elapsed;

		clio::Timer loopTimer(true);
		while (quit_ == false) {
			elapsed = loopTimer.Reset();
			lag += elapsed;

			Poll();

			//Update several times to make up for lag.
			while (lag >= SEC_PER_UPDATE) {
				Update();
				lag -= SEC_PER_UPDATE;
			}

			Render();
		}
	}

	void Game::Quit() {
		quit_ = true;
	}

	clio::GameStateStack * const Game::GetStateStack() {
		return stack_.get();
	}

	void Game::Poll() {
		if (stack_->IsEmpty()) {
			Quit();
		}
		else {
			system_->GetInput()->Poll(stack_->GetCurrentState().GetInputHandler());
		}
	}

	void Game::Update() {
		if (stack_->IsEmpty()) {
			Quit();
		}
		else {
			stack_->GetCurrentState().Update();
		}
	}

	void Game::Render() {
		if (stack_->IsEmpty()) {
			Quit();
		}
		else {
			stack_->GetCurrentState().Render();
		}
	}
}
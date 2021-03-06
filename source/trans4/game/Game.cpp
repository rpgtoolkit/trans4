/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "clio/common/Logger.hpp"
#include "clio/common/Timer.hpp"
#include "clio/game/GameState.hpp"
#include "clio/game/GameStateStack.hpp"
#include "clio/graphics/Renderer2D.hpp"
#include "clio/input/Input.hpp"
#include "clio/system/System.hpp"

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
			system_->GetRenderer()->ClearScreen();
			stack_->GetCurrentState().Render();
			system_->GetRenderer()->RenderDraws();
		}
	}
}
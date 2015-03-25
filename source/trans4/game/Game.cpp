/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "common/Logger.h"
#include "common/Timer.h"
#include "game/GameState.h"
#include "game/GameStateStack.h"
#include "input/Input.h"
#include "system/System.h"

#include "game/Game.hpp"

using namespace rpgtoolkit;
using clio::System;
using clio::GameStateStack;
using clio::Logger;
using clio::Timer;

const std::string Game::LOG = "game.log";

Game::Game(System* system) : log_(new Logger(LOG)), quit_(false), stack_(new GameStateStack()), system_(system) {
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
			Update();
			lag -= SEC_PER_UPDATE;
		}

		Render();
	}
}

void Game::Quit() {
	quit_ = true;
}

GameStateStack * const Game::GetStateStack() {
	return stack_.get();
}

void Game::Poll() {
	if (stack_->isEmpty()) {
		Quit();
	}
	else {
		system_->GetInput()->Poll(stack_->GetCurrentState().GetInputHandler());
	}
}

void Game::Update() {
	if (stack_->isEmpty()) {
		Quit();
	}
	else {
		stack_->GetCurrentState().Update();
	}
}

void Game::Render() {
	if (stack_->isEmpty()) {
		Quit();
	}
	else {
		stack_->GetCurrentState().Render();
	}
}
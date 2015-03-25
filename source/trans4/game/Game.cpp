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

Game::Game(System* system) : m_log(new Logger(LOG)), m_quit(false), m_stack(new GameStateStack()), m_system(system) {
}

Game::~Game() {
	delete m_stack;
	delete m_log;;
}

void Game::Run() {
	LOG(m_log, "Game started.");

	const double SEC_PER_UPDATE = .001; //1 millisecond
	double lag = 0, elapsed;

	Timer loopTimer(true);
	while (m_quit == false) {
		elapsed = loopTimer.Reset();
		lag += elapsed;

		Poll();

		while (lag >= SEC_PER_UPDATE) {
			Update();
			lag -= SEC_PER_UPDATE;
		}

		Render();
	}
}

void Game::Quit() {
	m_quit = true;
}

GameStateStack* Game::GetStateStack() {
	return m_stack;
}

void Game::Poll() {
	if (m_stack->isEmpty()) {
		Quit();
	}
	else {
		m_system->GetInput()->Poll(m_stack->GetCurrentState().GetInputHandler());
	}
}

void Game::Update() {
	if (m_stack->isEmpty()) {
		Quit();
	}
	else {
		m_stack->GetCurrentState().Update();
	}
}

void Game::Render() {
	if (m_stack->isEmpty()) {
		Quit();
	}
	else {
		m_stack->GetCurrentState().Render();
	}
}
#include "EmptyState.h"
#include "game/Game.h"
#include "game/GameState.h"
#include "input/Input.h"
#include "graphics/Renderer.h"
#include "system/Timer.h"

using namespace tk4;

Game::Game(Input* input, Renderer* renderer) 
	: m_input(input), m_gameOver(false), m_renderer(renderer) {
}

Game::~Game() {
	for (auto &s : m_states) {
		delete s;
	}
}

void Game::run() {
	const uint32_t MS_PER_UPDATE = 10;
	uint32_t lag = 0, elapsed;

	Timer loopTimer;
	loopTimer.start();
	while (m_input->shouldQuit() == false && m_gameOver == false) {
		elapsed = loopTimer.elapsed();
		lag += elapsed;
		loopTimer.reset();

		processInput();

		//Update game logic at a fixed rate, potentially several times 
		//to make up for lag in the game loop
		while (lag >= MS_PER_UPDATE) {
			update();
			lag -= MS_PER_UPDATE;
		}

		render();
	}
}

void Game::changeState(GameState* newState) {
	if (m_states.empty() == false) {
		GameState* old = m_states.back();
		m_states.pop_back();
		delete old;
	}

	m_states.push_back(newState);
	newState->initialize();
}

void Game::pushState(GameState* state) {
	if (m_states.empty() == false) {
		m_states.back()->pause();
	}

	m_states.push_back(state);
	state->initialize();
}

void Game::popState() {
	if (m_states.empty() == false) {
		GameState* old = m_states.back();
		m_states.pop_back();
		delete old;
	}

	if (m_states.empty() == false) {
		m_states.back()->resume();
	} else {
		m_gameOver = true;
	}
}

void Game::processInput() {
	if (m_states.empty() == false) {
		m_input->process(m_states.back()->getInputHandler());
	}
}

void Game::update() {
	if (m_states.empty() == false) {
		m_states.back()->update();
	}
}

void Game::render() {
	m_renderer->clearScreen();

	if (m_states.empty() == false) {
		m_states.back()->render(m_renderer);
	}

	m_renderer->renderScreen();
}
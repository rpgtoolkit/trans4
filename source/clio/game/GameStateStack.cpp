#include "game/GameState.h"
#include "game/GameStateStack.h"

using namespace clio;

GameStateStack::GameStateStack() {

}

GameStateStack::~GameStateStack() {

}

void GameStateStack::ClearAllStates() {
	m_states.clear();
}

void GameStateStack::ChangeState(std::unique_ptr<GameState> newState) {
	if (m_states.empty() == false) {
		m_states.pop_back();
	}

	m_states.push_back(std::move(newState));
	m_states.back()->Initialize();
}

void GameStateStack::PushState(std::unique_ptr<GameState> state) {
	if (m_states.empty() == false) {
		m_states.back()->Pause();
	}

	m_states.push_back(std::move(state));
	m_states.back()->Initialize();
}

void GameStateStack::PopState() {
	if (m_states.empty() == false) {
		m_states.pop_back();
	}

	if (m_states.empty() == false) {
		m_states.back()->Resume();
	}
}

GameState& GameStateStack::GetCurrentState() {
	return (*m_states.back().get());
}

bool GameStateStack::isEmpty() {
	return m_states.empty();
}
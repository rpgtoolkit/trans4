#include "common/Exception.hpp"
#include "game/GameState.hpp"
#include "game/GameStateStack.hpp"

namespace clio {

	GameStateStack::GameStateStack() {

	}

	GameStateStack::~GameStateStack() {

	}

	void GameStateStack::ClearAllStates() {
		states_.clear();
	}

	void GameStateStack::ChangeState(std::unique_ptr<GameState> newState) {
		if (states_.empty() == false) {
			states_.pop_back();
		}

		states_.push_back(std::move(newState));
		states_.back()->Initialize();
	}

	void GameStateStack::PushState(std::unique_ptr<GameState> state) {
		if (states_.empty() == false) {
			states_.back()->Pause();
		}

		states_.push_back(std::move(state));
		states_.back()->Initialize();
	}

	void GameStateStack::PopState() {
		if (states_.empty() == false) {
			states_.pop_back();
		}

		if (states_.empty() == false) {
			states_.back()->Resume();
		}
	}

	GameState& GameStateStack::GetCurrentState() {
		if (IsEmpty()) {
			throw clio::Exception("State Stack is empty. Cannot retrieve current state.");
		}
		return (*states_.back().get());
	}

	bool GameStateStack::IsEmpty() {
		return states_.empty();
	}
}
#pragma once

#include "game/GameState.h"

namespace tk4 {
	class EmptyState : public GameState {
	public:
		EmptyState(GameStateManager* stateManager) : GameState(stateManager) {}

		~EmptyState() {}

		void initialize() {}

		void pause() {}

		void resume() {}

		InputHandler* getInputHandler() { return nullptr; }

		void update() {}

		void render(Renderer* renderer) {}
	};
}
/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_GAME_EMPTYSTATE_INCLUDED
#define RPGTOOLKIT_TRANS4_GAME_EMPTYSTATE_INCLUDED

#include <trans4/game/GameState.hpp>

namespace rpgtoolkit {

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

#endif

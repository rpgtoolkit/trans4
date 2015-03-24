/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_GAME_GAMESTATEMANAGER_INCLUDED
#define RPGTOOLKIT_TRANS4_GAME_GAMESTATEMANAGER_INCLUDED

namespace rpgtoolkit {

	class GameState;

	/**
	* This is an interface for dealing with GameState transitions following a stack design.
	* You can push new states onto the stack, and the top of the stack is the state that is
	* currently running in the game. Popping states off the stack means the state underneath
	* is the next one in play (i.e. it will be unpaused).
	*/
	class GameStateManager {
	public:
		virtual ~GameStateManager() {}

		/**
		* Removes the current state and replaces it with a different one.
		*
		* @param newState The new game state
		*/
		virtual void changeState(GameState* newState) = 0;

		/**
		* Pauses the current state and adds a new state to the stack.
		*
		* @param state The new game state
		*/
		virtual void pushState(GameState* state) = 0;

		/**
		* Removes the current state and replaces it with the last state.
		*/
		virtual void popState() = 0;

		/**
		* No copying allowed.
		*/
		GameStateManager(GameStateManager const&) = delete;

		/**
		* No copying allowed.
		*/
		GameStateManager & operator=(GameStateManager const&) = delete;
	protected:
		GameStateManager() {}
	};
}

#endif

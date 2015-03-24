/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_GAME_GAMESTATE_INCLUDED
#define RPGTOOLKIT_TRANS4_GAME_GAMESTATE_INCLUDED

namespace rpgtoolkit {

	class GameStateManager;
	class InputHandler;
	class Renderer;

	/**
	* This is an interface for a game state. A game state is called by the
	* game loop when it is the current state. This allows it to update and
	* draw to the screen. The state can be paused or removed from the loop
	* at any time.
	*/
	class GameState {
	public:
		virtual ~GameState() {}

		/**
		* Initializes the game state and sets up all data required so
		* that the game state can run when called upon by the main
		* game loop.
		*/
		virtual void initialize() = 0;

		/**
		* Pause the game state, preventing progress until it is resumed
		* at a later time.
		*/
		virtual void pause() = 0;

		/**
		* Resume from pause.
		*/
		virtual void resume() = 0;

		/**
		* Retrieve the InputHandler of this game state.
		*
		* @return The class that handles input for this game state.
		*/
		virtual InputHandler* getInputHandler() = 0;

		/**
		* Update the game state's logic.
		*/
		virtual void update() = 0;

		/**
		* Rener the game state to the screen.
		*
		* @param renderer The renderer to use for drawing.
		*/
		virtual void render(Renderer* renderer) = 0;

		/**
		* No copying allowed.
		*/
		GameState(GameState const&) = delete;

		/**
		* No copying allowed.
		*/
		GameState & operator=(GameState const&) = delete;
	protected:
		GameState() : m_stateManager(nullptr) {}

		GameState(GameStateManager* stateManager) : m_stateManager(stateManager) {}

		GameStateManager* m_stateManager;
	};
}

#endif

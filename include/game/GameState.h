#pragma once

namespace tk4 {
	class GameStateManager;
	class InputHandler;
	class Renderer;

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

		virtual InputHandler* getInputHandler() = 0;

		virtual void update() = 0;

		virtual void render(Renderer* renderer) = 0;

		GameState(GameState const&) = delete;

		GameState & operator=(GameState const&) = delete;
	protected:
		GameState(GameStateManager* stateManager) : m_stateManager(stateManager) {}

		GameStateManager* m_stateManager;
	};
}
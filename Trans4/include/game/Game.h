#pragma once

#include <vector>

#include "GameStateManager.h"

namespace tk4 {
	class Input;
	class Renderer;

	/**
	* The game class is responsible for the game loop and managing
	* the different game states (e.g. Main Menu, Map, Battle, etc).
	*/
	class Game : public GameStateManager {
	public:
		Game(Input* input, Renderer* renderer);

		~Game();

		/**
		* Run the game in the main game loop.
		*/
		void run();

		void changeState(GameState* newState);

		void pushState(GameState* state);

		void popState();

		Game(Game const&) = delete;

		Game & operator=(Game const&) = delete;
	private:
		void processInput();
		
		void render();

		void update();		

		Input* m_input;

		bool m_gameOver;

		std::vector<GameState*> m_states;

		Renderer* m_renderer;
	};
}
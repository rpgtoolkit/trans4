/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_GAME_GAME_INCLUDED
#define RPGTOOLKIT_TRANS4_GAME_GAME_INCLUDED

#include <vector>
#include <trans4/game/GameStateManager.hpp>

namespace rpgtoolkit {

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

#endif

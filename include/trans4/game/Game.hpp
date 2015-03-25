#pragma once

#include <string>

namespace clio {
	class GameStateStack;
	class Logger;
	class System;
}

namespace rpgtoolkit {

	/**
	* The game class is responsible for the game loop.
	*/
	class Game {
	public:
		const static std::string LOG;

		/**
		* Constructor.
		*/
		Game(clio::System* system);

		/**
		* Destructor.
		*/
		~Game();

		/**
		* Run the main game loop.
		*/
		void Run();

		/**
		* Quit the game.
		*/
		void Quit();

		clio::GameStateStack* GetStateStack();

		/**
		* No copying allowed.
		*/
		Game(Game const&) = delete;

		/**
		* No copying allowed.
		*/
		Game & operator=(Game const&) = delete;
	private:
		clio::Logger* m_log;

		bool m_quit;

		clio::GameStateStack* m_stack;

		clio::System* m_system;

		void Poll();

		void Update();

		void Render();
	};
}
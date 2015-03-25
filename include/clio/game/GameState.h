#pragma once

#include "input/InputContext.h"

namespace clio {
	class GameStateStack;
	class Renderer2D;

	/**
	* This is an interface for a game state. A game state is called by the
	* game loop when it is the current state. This allows it to update and
	* draw to the screen. The state can be paused or removed from the loop
	* at any time.
	*/
	class GameState {
	public:
		/**
		* Destructor.
		*/
		virtual ~GameState() {}

		/**
		* Initializes the game state and sets up all data required so 
		* that the game state can run when called upon by the main
		* game loop.
		*/
		virtual void Initialize() = 0;

		/**
		* Pause the game state, preventing progress until it is resumed
		* at a later time.
		*/
		virtual void Pause() = 0;

		/**
		* Resume from pause.
		*/
		virtual void Resume() = 0;

		/**
		* Update the game state's logic.
		*/
		virtual void Update() = 0;

		/**
		* Rener the game state to the screen.
		*/
		virtual void Render() = 0;

		virtual InputHandler* GetInputHandler() { return m_inputContext; }

		/**
		* No copying allowed.
		*/
		GameState(GameState const&) = delete;

		/**
		* No copying allowed.
		*/
		GameState & operator=(GameState const&) = delete;
	protected:
		/**
		* Constructor.
		*/
		GameState() : GameState(nullptr, nullptr) {}

		/**
		* Constructor.
		*/
		GameState(GameStateStack* stateStack, Renderer2D* renderer) : 
			m_stateStack(stateStack), m_inputContext(new InputContext()), m_renderer(renderer) {}

		GameStateStack* m_stateStack;

		InputContext* m_inputContext;

		Renderer2D* m_renderer;
	};
}
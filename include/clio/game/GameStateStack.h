#pragma once

#include <memory>
#include <vector>

namespace clio {
	class GameState;

	/**
	* This class deals with GameState transitions following a stack design.
	* You can push new states onto the stack, and the top of the stack is the state that is
	* currently running in the game. Popping states off the stack means the state underneath
	* is the next one in play (i.e. it will be unpaused).
	*/
	class GameStateStack {
	public:
		/**
		* Constructor.
		*/
		GameStateStack();

		/**
		* Destructor.
		*/
		virtual ~GameStateStack();

		/**
		* Remove and clear all states on the stack.
		*/
		virtual void ClearAllStates();

		/**
		* Removes the current state and replaces it with a different one.
		*
		* @param newState The new game state
		*/
		virtual void ChangeState(std::unique_ptr<GameState> newState);

		/**
		* Pauses the current state and adds a new state to the stack.
		*
		* @param state The new game state
		*/
		virtual void PushState(std::unique_ptr<GameState> state);

		/**
		* Removes the current state and replaces it with the last state.
		*/
		virtual void PopState();

		/**
		* Retrieve the state at the top of the stack.
		*
		* @return the state at the top of the stack.
		*/
		virtual GameState& GetCurrentState();

		/**
		* Check if the stack is empty or not.
		*
		* @return true if the state is empty, false otherwise.
		*/
		virtual bool isEmpty();

		/**
		* No copying allowed.
		*/
		GameStateStack(GameStateStack const&) = delete;

		/**
		* No copying allowed.
		*/
		GameStateStack & operator=(GameStateStack const&) = delete;
	private:
		std::vector<std::unique_ptr<GameState> > m_states;
	};
}
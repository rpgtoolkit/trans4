#pragma once

#include <memory>
#include <vector>

namespace clio {
	class GameState;

	
	/// This class deals with GameState transitions following a stack design.
	/// You can push new states onto the stack, and the top of the stack is the state that is
	/// currently running in the game. Popping states off the stack means the state underneath
	/// is the next one in play (i.e. it will be unpaused).
	class GameStateStack {
	public:
		/// \brief Constructor.
		GameStateStack();
				
		/// \brief Destructor.
		virtual ~GameStateStack();
				
		/// \brief Remove and clear all states on the stack.
		virtual void ClearAllStates();
				
		/// \brief Removes the current state and replaces it with a different one.
		///
		/// \param newState The new game state
		virtual void ChangeState(std::unique_ptr<GameState> newState);
				
		/// \brief Pauses the current state and adds a new state to the stack.
		///
		/// \param state The new game state
		virtual void PushState(std::unique_ptr<GameState> state);
				
		/// \brief Removes the current state and replaces it with the last state.
		virtual void PopState();
				
		/// \brief Retrieve the state at the top of the stack.
		///
		/// \return the state at the top of the stack.
		virtual GameState& GetCurrentState();
				
		/// \brief Check if the stack is empty or not.
		///
		/// \return true if the state is empty, false otherwise.
		virtual bool IsEmpty();
				
		/// \brief No copying allowed.
		GameStateStack(GameStateStack const&) = delete;
		
		/// \brief No copying allowed.
		GameStateStack & operator=(GameStateStack const&) = delete;
	private:
		std::vector<std::unique_ptr<GameState> > states_;
	};
}
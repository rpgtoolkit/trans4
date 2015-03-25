#pragma once

#include <memory>

#include "input/InputContext.hpp"

namespace clio {
	class GameStateStack;
	class Renderer2D;

	///
	/// This is an interface for a game state. A game state is called by the
	/// game loop when it is the current state. This allows it to update and
	/// draw to the screen. The state can be paused or removed from the loop
	/// at any time.
	///
	class GameState {
	public:
		/// \brief Destructor.
		virtual ~GameState() {}

		/// Initializes the game state and sets up all data required so 
		/// that the game state can run when called upon by the main
		/// game loop.
		virtual void Initialize() = 0;

		/// Pause the game state, preventing progress until it is resumed
		/// at a later time with Resume.
		virtual void Pause() = 0;

		/// \brief Resume from pause.
		virtual void Resume() = 0;

		/// \brief Update the game state's logic.
		virtual void Update() = 0;

		/// \brief Render the game state to the screen.
		virtual void Render() = 0;

		/// \brief Get the InputHandler for this game state that will take care of input events.
		///
		/// \return A raw pointer for temporary use, to be called on to handle input events.
		virtual InputHandler* GetInputHandler() { return input_context_.get(); }

		/// \brief No copying allowed.
		GameState(GameState const&) = delete;

		/// \brief No copying allowed.
		GameState & operator=(GameState const&) = delete;
	protected:
		/// \brief Constructor.
		GameState() : GameState(nullptr, nullptr) {}

		/// \brief Constructor.
		GameState(GameStateStack* state_stack, Renderer2D* renderer) : 
			state_stack_(state_stack), input_context_(new InputContext()), renderer_(renderer) {}

		/// \brief We do not own the game state stack, so we use a raw pointer.
		GameStateStack* state_stack_;

		/// We own the input context that will handle input events.
		std::unique_ptr<InputContext> input_context_;

		/// We do not own the renderer, so we use a raw pointer.
		Renderer2D* renderer_;
	};
}
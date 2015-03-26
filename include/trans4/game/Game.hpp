#ifndef RPGTOOLKIT_TRANS4_GAME_GAME_INCLUDED
#define RPGTOOLKIT_TRANS4_GAME_GAME_INCLUDED

#include <memory>
#include <string>

namespace clio {

    class GameStateStack;
	class Logger;
	class System;

}

namespace rpgtoolkit {

    /// \brief The game class is responsible for the game loop.
    ///
    /// The object contains a GameStateStack to manage the different
    /// game states of the game.

	class Game {
	public:

        /// \brief The string corresponding to a Game log file
        const static std::string LOG;

        /// \brief Constructor
        ///
        /// \param system The system with which to interact.
        Game(clio::System *system);

        /// \brief Destructor
        ~Game();

        /// \brief Run the game loop until Quit() is called
        void Run();

        /// \brief Quit the game.
        void Quit();

        /// \brief Get the game stack.
        clio::GameStateStack *const GetStateStack();

        /// \brief No copying allowed.
        Game(Game const &) = delete;

        /// \brief No copying allowed.
        Game & operator=(Game const &) = delete;

    private:
        /// \brief Logger for this class.
        std::unique_ptr<clio::Logger> log_;

        /// \brief Whether the game loop continues or not.
        bool quit_;

        /// \brief Manages the game states.
        std::unique_ptr<clio::GameStateStack> stack_;

        /// \brief The underlying system.
        clio::System *system_;

        /// \brief Helper function to poll input.
        void Poll();

        /// \brief Helper function to update state(s).
        void Update();

        /// \brief Helper function to render to the screen.
        void Render();
    };
}

#endif
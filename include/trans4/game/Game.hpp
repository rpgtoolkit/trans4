#ifndef RPGTOOLKIT_TRANS4_GAME_GAME_INCLUDED
#define RPGTOOLKIT_TRANS4_GAME_GAME_INCLUDED

#include <memory>
#include <string>

namespace rpgtoolkit {

    /// \brief The game class is responsible for the game loop.
    ///
    /// The object contains a GameStateStack to manage the different
    /// game states of the game.

	struct Game {
	public:

        /// \brief The string corresponding to a Game log file
        const static std::string LOG;

        /// \brief Constructor
        Game();

        /// \brief Destructor
        ~Game();

        /// \brief Run the game loop until Quit() is called
        void Run();

        /// \brief Quit the game.
        void Quit();

        /// \brief No copying allowed.
        Game(Game const &) = delete;

        /// \brief No copying allowed.
        Game & operator=(Game const &) = delete;

    private:
        /// \brief Logger for this class.
        std::unique_ptr<Logger> log_;

        /// \brief Whether the game loop continues or not.
        bool quit_;

        /// \brief Helper function to poll input.
        void Poll();
    };
}

#endif
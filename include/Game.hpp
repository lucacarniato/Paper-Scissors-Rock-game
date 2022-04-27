#pragma once
#include <memory>

#include <Player.hpp>
#include <Rules.hpp>

/// \namespace paperscissorrock_game
/// @brief Contains the implementation of the game
namespace paperscissorrock_game
{
    /// @brief The game, storing the game statistics
    class Game
    {
    public:
        /// @brief Constructor
        /// @param[in] rules A reference to a rule class instance
        /// @param[in] firstPlayer A pointer to the first player of the game
        /// @param[in] secondPlayer A pointer to the second player of the game
        Game(const Rules& rules,
             std::shared_ptr<Player> firstPlayer,
             std::shared_ptr<Player> secondPlayer);

        /// @brief Gets the winner of the current round
        /// @return The name of the winning player
        [[nodiscard]] std::string getRoundWinner();

        /// @brief Gets the current results of the game
        /// @return The results of the game
        [[nodiscard]] const auto& getGameResults() const { return gameResults_; };

    private:
        Rules rules_;
        std::shared_ptr<Player> firstPlayer_;                 ///< The first player of the game
        std::shared_ptr<Player> secondPlayer_;                ///< The second player of the game
        std::unordered_map<std::string, size_t> gameResults_; ///< The game's results, with keys the player's names and values the number of won rounds for each player
    };
} // namespace paperscissorrock_game

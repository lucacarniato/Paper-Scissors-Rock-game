#pragma once
#include <memory>

#include <Player.hpp>

/// \namespace paperscissorrock_game
/// @brief Contains the implementation of the game
namespace paperscissorrock_game
{
    /// @brief A factory for players
    struct PlayersFactory
    {
        /// @brief Creates a human player
        /// @return A shared_ptr referencing to a HumanPlayer instance
        [[nodiscard]] static std::shared_ptr<Player> createHumanPlayer();

        /// @brief Creates a computer player
        /// @param[in] numRounds The number of game rounds
        /// @return A shared_ptr referencing to a ComputerPlayer instance
        [[nodiscard]] static std::shared_ptr<Player> createComputerPlayer(size_t numRounds);
    };
} // namespace paperscissorrock_game
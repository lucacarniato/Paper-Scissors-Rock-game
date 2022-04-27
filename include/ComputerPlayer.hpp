#pragma once
#include <array>
#include <string>

#include <Hands.hpp>
#include <Player.hpp>
#include <random>

/// \namespace paperscissorrock_game
/// @brief Contains the implementation of the game
namespace paperscissorrock_game
{
    /// @brief The computer player
    class ComputerPlayer : public Player
    {
    public:
        /// @brief Constructor
        /// @param[in] name The player's name
        /// @param[in] seed The seed value for the random number generator
        /// @param[in] numRounds The number of game rounds
        ComputerPlayer(const std::string& name, unsigned int seed, size_t numRounds);

        /// @brief Gets the player's hand
        /// @return The player's hand
        [[nodiscard]] Hands getHand() override;

    private:
        const std::array<Hands, 3> indexedHands_{ Hands::Scissor, Hands::Rock, Hands::Paper }; ///< Internal array to map an index from 0 to 2 to an hand type
        unsigned int seed_;                                                                    ///< The random seed
        size_t numRounds_;                                                                     ///< The number of rounds
        std::vector<size_t>  randomIndexses_;                                                  ///< The random generated indexses
        size_t currentRound_;                                                                  ///< The current round
    };

} // namespace paperscissorrock_game
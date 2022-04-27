#pragma once
#include <string>
#include <unordered_map>
#include <utility>

#include <Hands.hpp>
#include <Player.hpp>

/// \namespace paperscissorrock_game
/// @brief Contains the implementation of the game
namespace paperscissorrock_game
{
    /// @brief The human player
    class HumanPlayer : public Player
    {
    public:
        /// @brief Constructor
        /// @param[in] name The player's name
        explicit HumanPlayer(const std::string& name);

        /// @brief Gets the player's hand
        /// @return The player's hand
        [[nodiscard]] Hands getHand() override;

    private:
        const std::unordered_map<char, Hands> charToHands_{
            {'P', Hands::Paper},
            {'R', Hands::Rock},
            {'S', Hands::Scissor},
        }; ///< Internal structure to map a char to an hand type
    };
} // namespace paperscissorrock_game

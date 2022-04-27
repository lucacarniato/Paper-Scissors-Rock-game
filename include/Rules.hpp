#pragma once
#include <memory>
#include <set>
#include <unordered_map>

#include <Hands.hpp>
#include <Player.hpp>

/// \namespace paperscissorrock_game
/// @brief Contains the implementation of the game
namespace paperscissorrock_game
{
    /// @brief A class containing the rules table and computing the winners
    class Rules
    {
    public:
        /// @brief Constructor
        /// @param rulesTable The rules table
        explicit Rules(std::unordered_map<Hands, std::set<Hands>> rulesTable);

        /// @brief Computes the winner based on the rule table
        /// @param[in] firstPlayer The first player
        /// @param[in] secondPlayer The second player
        /// @param[in] tiePlayer The player who wins if there is a tie
        /// @return The winner name based on the rule set
        [[nodiscard]] std::string getWinner(const std::shared_ptr<Player>& firstPlayer, const std::shared_ptr<Player>& secondPlayer) const;

        inline static const std::string tie{ "Tie" }; ///< A string indicating a tie

    private:
        const std::unordered_map<Hands, std::set<Hands>> rulesTable_; ///< The structure with the rules. The key indicates an hand type and the values the other loosing hands
    };
} // namespace paperscissorrock_game
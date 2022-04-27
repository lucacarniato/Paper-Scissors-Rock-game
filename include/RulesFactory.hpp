#pragma once
#include <Rules.hpp>

/// \namespace paperscissorrock_game
/// @brief Contains the implementation of the game
namespace paperscissorrock_game
{
    struct RulesFactory
    {
        /// @brief Creates Rules with the default rules of the game
        /// @return Rules with default rules
        [[nodiscard]] static Rules createDefaultRules();

        /// @brief Creates Rules with strange rules, where scissors never wins and Paper can win against scissors
        /// @return Rules with strange rules
        [[nodiscard]] static Rules createStrangeRules();
    };
} // namespace paperscissorrock_game
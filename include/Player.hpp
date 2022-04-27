#pragma once
#include <string>

#include <Hands.hpp>

/// \namespace paperscissorrock_game
/// @brief Contains the implementation of the game
namespace paperscissorrock_game
{
    /// @brief Abstract class for players
    class Player
    {
    public:
        /// @brief Constructor
        /// @param[in] name The player's name
        explicit Player(const std::string& name)
            : name_(name)
        {
        }

        /// @brief Virtual destructor, to ensure proper destruction of derived types referenced with a base class pointer
        virtual ~Player() = default;

        /// @brief Gets the player's hand
        /// @return The player's hand
        [[nodiscard]] virtual Hands getHand() = 0;

        /// @brief Gets the player's name
        /// @return The player's name
        [[nodiscard]] auto const& getName() const { return name_; }

    private:
        std::string name_; ///< the player's name
    };
} // namespace paperscissorrock_game

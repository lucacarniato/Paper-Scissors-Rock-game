#include <memory>
#include <utility>

#include <Game.hpp>
#include <Player.hpp>
#include <Rules.hpp>

using namespace paperscissorrock_game;

Game::Game(const Rules& rules,
           std::shared_ptr<Player> firstPlayer,
           std::shared_ptr<Player> secondPlayer)
    : rules_(rules),
      firstPlayer_(std::move(firstPlayer)),
      secondPlayer_(std::move(secondPlayer))
{
    gameResults_.try_emplace(firstPlayer_->getName(), 0);
    gameResults_.try_emplace(secondPlayer_->getName(), 0);
    gameResults_.try_emplace(Rules::tie, 0);
}

std::string Game::getRoundWinner()
{
    auto result = rules_.getWinner(firstPlayer_, secondPlayer_);
    gameResults_.at(result) += 1;
    return result;
}
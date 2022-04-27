#include <memory>
#include <set>
#include <unordered_map>
#include <utility>

#include <Hands.hpp>
#include <Player.hpp>
#include <Rules.hpp>

using namespace paperscissorrock_game;

Rules::Rules(std::unordered_map<Hands, std::set<Hands>> rulesTable)
    : rulesTable_(std::move(rulesTable))
{
}

std::string Rules::getWinner(const std::shared_ptr<Player>& firstPlayer,
                             const std::shared_ptr<Player>& secondPlayer) const
{
    const auto firstPlayerHand = firstPlayer->getHand();
    const auto secondPlayerHand = secondPlayer->getHand();

    const auto firstPlayerWinsAgainstHands = rulesTable_.at(firstPlayerHand);
    if (firstPlayerWinsAgainstHands.find(secondPlayerHand) != firstPlayerWinsAgainstHands.end())
    {
        return firstPlayer->getName();
    }
    const auto secondPlayerWinsAgainstHands = rulesTable_.at(secondPlayerHand);
    if (secondPlayerWinsAgainstHands.find(firstPlayerHand) != secondPlayerWinsAgainstHands.end())
    {
        return secondPlayer->getName();
    }
    return tie;
}

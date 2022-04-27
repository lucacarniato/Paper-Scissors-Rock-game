#include <random>

#include <ComputerPlayer.hpp>
#include <HumanPlayer.hpp>
#include <PlayersFactory.hpp>

using namespace paperscissorrock_game;

std::shared_ptr<Player> PlayersFactory::createHumanPlayer()
{
    return std::make_shared<HumanPlayer>("Human");
}
std::shared_ptr<Player> PlayersFactory::createComputerPlayer(size_t numRounds)
{
    return std::make_shared<ComputerPlayer>("Computer", std::random_device()(), numRounds);
};
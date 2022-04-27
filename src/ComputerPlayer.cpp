#include <array>
#include <random>
#include <stdexcept>

#include <ComputerPlayer.hpp>
#include <Hands.hpp>
#include <Player.hpp>


using namespace paperscissorrock_game;

ComputerPlayer::ComputerPlayer(const std::string& name, unsigned int seed, size_t numRounds) : Player(name), seed_(seed), numRounds_(numRounds)
{
    currentRound_ = 0;
    std::uniform_int_distribution<size_t> distribution(0, indexedHands_.size() - 1);
    std::mt19937 generator(seed_);
    randomIndexses_.resize(numRounds_);
    for (auto i = 0; i < numRounds_; ++i)
    {
        randomIndexses_[i] = distribution(generator);
    }
}

Hands ComputerPlayer::getHand()
{
    if (currentRound_ >= randomIndexses_.size())
    {
        throw  std::invalid_argument("Current round exceeds the number of the rounds in the game");
    }
    auto hand = indexedHands_[randomIndexses_[currentRound_]];
    currentRound_++;
    return hand;

}

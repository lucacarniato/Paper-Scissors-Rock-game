#include <iostream>
#include <string>

#include <Hands.hpp>
#include <HumanPlayer.hpp>
#include <Player.hpp>

using namespace paperscissorrock_game;

HumanPlayer::HumanPlayer(const std::string& name) : Player(name) {};

Hands HumanPlayer::getHand()
{
    while (true)
    {
        std::cout << "Enter a single capital letter: (P) for Paper, (R) for rock, and (S) for scissor " << std::endl;
        std::string choice;
        std::cin >> choice;
        if (choice.length() != 1)
        {
            std::cout << "You must enter a single letter! " << std::endl;
            continue;
        }
        const auto it = charToHands_.find(choice[0]);
        if (it == charToHands_.end())
        {
            std::cout << "Letter not available, please retry! " << std::endl;
            continue;
        }
        return it->second;
    }
}

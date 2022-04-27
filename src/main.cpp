#include <iostream>

#include <Game.hpp>
#include <HumanPlayer.hpp>
#include <PlayersFactory.hpp>
#include <Rules.hpp>
#include <RulesFactory.hpp>

using namespace paperscissorrock_game;

int main()
{
    try
    {
        std::cout << "Welcome to rock, paper and scissors Game!" << std::endl;
        std::cout << "Please enter the number of rounds you want to play" << std::endl;
        int rounds;
        std::cin >> rounds;

        const auto firstPlayer = PlayersFactory::createComputerPlayer(rounds);
        const auto secondPlayer = PlayersFactory::createHumanPlayer();
        const auto rules = RulesFactory::createDefaultRules();

        auto game = Game(rules, firstPlayer, secondPlayer);

        for (auto i = 0; i < rounds; ++i)
        {
            std::cout << "Round " << std::to_string(i) << std::endl;
            const auto winner = game.getRoundWinner();
            if (winner != Rules::tie)
            {
                std::cout << winner << " won this round " << std::endl;
            }
            else
            {
                std::cout << "It's a tie " << std::endl;
            }
        }

        const auto gameResults = game.getGameResults();
        for (const auto& [name, winCount] : gameResults)
        {
            std::cout << name << " won " << std::to_string(winCount) << " rounds" << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "std::exception thrown: " << e.what() << std::endl;
        return -1;
    }
    catch (...)
    {
        std::cout << "Exception thrown! " << std::endl;
        return -1;
    }
    return 0;
}

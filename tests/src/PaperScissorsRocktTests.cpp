#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <ComputerPlayer.hpp>
#include <Game.hpp>
#include <HumanPlayer.hpp>
#include <RulesFactory.hpp>

using namespace paperscissorrock_game;

class MockedHumanPlayer : public HumanPlayer
{
public:
    explicit MockedHumanPlayer(const std::string& name) : HumanPlayer(name)
    {
    }

    MOCK_METHOD(Hands, getHand, (), ());
};
TEST(Players, ComputerPlayer_WithFixedSeed_ShouldDrawExpectedHands)
{
    // Prepare
    const size_t numRounds{ 5 };
    const auto player = std::make_shared<ComputerPlayer>("Computer", 42, numRounds);

    // Execute
    std::vector<Hands> results;
    const size_t numDraws{ 5 };
    for (auto i = 0; i < numDraws; ++i)
    {
        results.emplace_back(player->getHand());
    }

    // Assert
    std::vector<Hands> expectedResults{
        Hands::Scissor,
        Hands::Paper,
        Hands::Rock,
        Hands::Rock,
        Hands::Scissor };

    ASSERT_THAT(results, ::testing::ContainerEq(expectedResults));
}

TEST(Rule, SimpleRules_WithComputerPlayerAndMockedHumanPlayer_ShouldComputeExpectedWinners)
{
    // Prepare
    const size_t numRounds{ 5 };
    const auto rules = RulesFactory::createDefaultRules();
    const auto computerPlayer = std::make_shared<ComputerPlayer>("Computer", 42, numRounds);
    const auto humanPlayer = std::make_shared<MockedHumanPlayer>("MockedHumanPlayer");

    EXPECT_CALL(*humanPlayer.get(), getHand()).WillRepeatedly(testing::Return(Hands::Rock));

    // Execute
    std::vector<std::string> results(numRounds);
    for (auto i = 0; i < results.size(); ++i)
    {
        results[i] = rules.getWinner(computerPlayer, humanPlayer);
    }

    // Assert
    std::vector<std::string> expectedResults{
        humanPlayer->getName(),
        computerPlayer->getName(),
        Rules::tie,
        Rules::tie,
        humanPlayer->getName() };

    ASSERT_THAT(results, ::testing::ContainerEq(expectedResults));
}

TEST(Rule, StrangeRules_WithComputerPlayerAndMockedHumanPlayer_ShouldComputeExpectedWinners)
{
    // Prepare
    const size_t numRounds{ 5 };
    const auto rules = RulesFactory::createStrangeRules();
    const auto computerPlayer = std::make_shared<ComputerPlayer>("Computer", 42, numRounds);
    const auto humanPlayer = std::make_shared<MockedHumanPlayer>("MockedHumanPlayer");

    EXPECT_CALL(*humanPlayer.get(), getHand()).WillRepeatedly(testing::Return(Hands::Scissor));

    // Execute
    std::vector<std::string> results(numRounds);
    for (auto i = 0; i < results.size(); ++i)
    {
        results[i] = rules.getWinner(computerPlayer, humanPlayer);
    }

    // Assert
    std::vector<std::string> expectedResults{
        Rules::tie,
        computerPlayer->getName(),
        computerPlayer->getName(),
        computerPlayer->getName(),
        Rules::tie };

    ASSERT_THAT(results, ::testing::ContainerEq(expectedResults));
}

TEST(Game, Game_WithComputerPlayerAndMockedHumanPlayer_ShouldComputeExpectedResults)
{
    // Prepare
    const size_t numRounds{ 5 };
    const auto rules = RulesFactory::createDefaultRules();
    const auto computerPlayer = std::make_shared<ComputerPlayer>("Computer", 42, numRounds);
    const auto humanPlayer = std::make_shared<MockedHumanPlayer>("MockedHumanPlayer");
    auto game = Game(rules, computerPlayer, humanPlayer);

    EXPECT_CALL(*humanPlayer.get(), getHand()).WillRepeatedly(testing::Return(Hands::Rock));

    // Execute
    std::vector<std::string> gameWinners(numRounds);
    for (auto i = 0; i < gameWinners.size(); ++i)
    {
        gameWinners[i] = game.getRoundWinner();
    }
    const auto results = game.getGameResults();

    // Assert
    std::unordered_map<std::string, size_t> expectedResults{
        {"Computer", 1},
        {"MockedHumanPlayer", 2},
        {Rules::tie, 2} };

    ASSERT_THAT(results, ::testing::ContainerEq(expectedResults));
}
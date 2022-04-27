#include <Rules.hpp>
#include <RulesFactory.hpp>

using namespace paperscissorrock_game;

Rules RulesFactory::createDefaultRules()
{
    const std::unordered_map<Hands, std::set<Hands>> rulesTable{
        {Hands::Paper, {Hands::Rock}},
        {Hands::Rock, {Hands::Scissor}},
        {Hands::Scissor, {Hands::Paper}},
    };

    return Rules(rulesTable);
}

Rules RulesFactory::createStrangeRules()
{
    const std::unordered_map<Hands, std::set<Hands>> rulesTable{
        {Hands::Paper, {Hands::Rock, Hands::Scissor}},
        {Hands::Rock, {Hands::Scissor}},
        {Hands::Scissor, {}},
    };

    return Rules(rulesTable);
}

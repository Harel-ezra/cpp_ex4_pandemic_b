#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
namespace pandemic
{
    class Researcher : public Player
    {
    public:
        Researcher(Board &b, City c): Player(b,c)
        {}

        ~Researcher()
        {}
        Researcher& discover_cure(Color c) override;
        std::string role() override
        {
            return "Researcher";
        }
    };
}
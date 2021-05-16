#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
namespace pandemic
{
    class Scientist : public Player
    {
    private:
        int number_cars_for_discover_cure;
    public:
        Scientist(Board &b, City c, int number): Player(b,c), number_cars_for_discover_cure(number)
        {}

        ~Scientist()
        {}
        Scientist& discover_cure(Color c) override;
        std::string role() override
        {
            return "Scientist";
        }
    };
}
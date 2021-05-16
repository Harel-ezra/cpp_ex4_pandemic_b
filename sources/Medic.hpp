#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
namespace pandemic
{
    class Medic : public Player
    {
    public:
        Medic(Board &b, City c): Player(b,c)
        {}

        ~Medic()
        {}

        Medic& drive(City c) override;
        Medic& fly_direct (City c)override;
        Medic& fly_charter(City c)override;
        Medic& fly_shuttle(City c)override;
        Medic& treat(City c)override;
        std::string role() override
        {
            return "Medic";
        }
    };
}
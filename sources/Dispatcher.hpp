#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
namespace pandemic
{
    class Dispatcher : public Player
    {
    public:
        Dispatcher(Board &b, City c): Player(b,c)
        {}

        ~Dispatcher()
        {}
        Dispatcher& fly_direct (City c) override;
        std::string role() override
        {
            return "Dispatcher";
        }
    };
}
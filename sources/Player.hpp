#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>

namespace pandemic
{
//    struct game_cards
//    {
//        City city;
//        Color color;
//    };

    class Player
    {


    protected:
        Board &board;
        City city;
        std::set<City> player_cards;

        static void same_city_exaeption(City c1, City c2);

        int sum_color_cards(Color c);

        void remove_5_color_card(Color c);

    public:
        Player(Board &b, City c):board(b), city(c)
        {}

        ~Player()
        {}

        virtual Player& drive(City c);
        virtual Player& fly_direct (City c);
        virtual Player& fly_charter(City c);
        virtual Player& fly_shuttle(City c);
        virtual Player& build();
        virtual Player& discover_cure(Color c);
        virtual Player& treat(City c);
        virtual Player& take_card(City c);
        virtual std::string role()=0;
        virtual Player& remove_cards();

    };
}
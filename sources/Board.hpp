#pragma once

#include <iostream>
#include "City.hpp"
#include "Color.hpp"
//#include "Player.hpp"

#include <map>
#include <unordered_map>

#include <set>
//class Player; //for next

namespace pandemic {
    struct city_info
    {
        City city;
        Color color;
        std::set<City> neighbors;
        //std::set<Player> player_in_city;
        int disease_level;
        bool research_station;
    };
    struct cure //all cure are find or not
    {
        bool Blue= false;
        bool Black= false;
        bool Yellow= false;
        bool Red= false;
    };


    class Board {
    private:
        std::unordered_map<City, city_info> board_game={};
        cure cure_is_discover;
        void init();

    public:
        Board() {
            init();
        }

        ~Board() {}

        int& operator[](City c);
        //const int operator[](City c)const;
        //void operator=(int dis);

        bool is_clean() const;
        void remove_cures();
        void remove_stations();
        //void move_player(Player p,City src,City dest);
        Color color_of_city(City c);
        bool has_neighbors(City src, City dest) const;
        bool have_research_station(City c) const;
        void build_research_station(City c);
        void discover_cure(Color c);
        bool have_cure(Color c) const;
        int disease_level(City c); //return the disease_level of the city
        friend std::ostream &operator<<(std::ostream &output, const Board &board);
    };
}

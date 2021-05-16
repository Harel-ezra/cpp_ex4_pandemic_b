#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Scientist& Scientist::discover_cure(Color c)
{
    if(!board.have_research_station(this->city))
    {
        throw ("cant discover cure, no have research station in the city");
    }
    if(!board.have_cure(c) && sum_color_cards(c)>=number_cars_for_discover_cure)
    {
        int sum=0;
        for (City city: player_cards)
        {
            if(board.color_of_city(city)==c)
            {
                player_cards.erase(city);
                sum++;
            }
            if(number_cars_for_discover_cure==sum)
            {
                break;
            }
        }
        board.discover_cure(c);
    }
    return *this;
}



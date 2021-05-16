#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Scientist& Scientist::discover_cure(Color c)
{
    if(!board.have_research_station(this->city))
    {
        throw ("cant discover cure, no have research station in the city");
    }
    if(sum_color_cards(c)<number_cars_for_discover_cure)
    {
        throw ("cant discover cure, no enough cards");
    }
    if(!board.have_cure(c))
    {
        int sum=0;
        set<City> tempset=player_cards;
        for (City city: tempset)
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



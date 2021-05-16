#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

GeneSplicer& GeneSplicer::discover_cure(Color c)
{
    if(!board.have_research_station(this->city))
    {
        throw ("cant discover cure, no have research station in the city");
    }
    if(player_cards.size()<5)
    {
        throw ("cant discover cure, no enough cards");
    }
    if(!board.have_cure(c))
    {
        for(int i=0;i<5;i++)
        {//remove 5 cards
            player_cards.erase(player_cards.begin());
        }
        board.discover_cure(c);
    }
    return *this;
}


#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

const int five=5; // const number declere on 5
GeneSplicer& GeneSplicer::discover_cure(Color c)
{
    if(!board.have_research_station(this->city))
    {
        throw ("cant discover cure, no have research station in the city");
    }
    if(player_cards.size()<five)
    {
        throw ("cant discover cure, no enough cards");
    }
    if(!board.have_cure(c))
    {
        for(int i=0;i<five;i++)
        {//remove 5 cards
            player_cards.erase(player_cards.begin());
        }
        board.discover_cure(c);
    }
    return *this;
}


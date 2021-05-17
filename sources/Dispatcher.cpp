#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

Dispatcher& Dispatcher::fly_direct (City c)
{
    if(board.have_research_station(this->city))
    {
        same_city_exaeption(this->city,c);
        this->city=c;
    }
    else
    {
        Player::fly_direct(c);
    }
    return *this;
}



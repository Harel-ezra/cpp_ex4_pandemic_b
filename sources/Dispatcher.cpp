#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

Dispatcher& Dispatcher::fly_direct (City c)
{
    same_city_exaeption(this->city,c);
    this->city=c;
    return *this;
}



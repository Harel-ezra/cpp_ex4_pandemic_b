#include "OperationsExpert.hpp"
using namespace std;
using namespace pandemic;

OperationsExpert& OperationsExpert::build()
{
        if(!board.have_research_station(this->city))
        {
            board.build_research_station(this->city);
        }
        return *this;
}



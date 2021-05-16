//#include "../doctest.h"
#include "sources/Board.hpp"
#include "sources/City.hpp"
#include "sources/Color.hpp"
#include "sources/Player.hpp"

#include "sources/Researcher.hpp"
#include "sources/Scientist.hpp"
#include "sources/FieldDoctor.hpp"
#include "sources/GeneSplicer.hpp"
#include "sources/OperationsExpert.hpp"
#include "sources/Dispatcher.hpp"
#include "sources/Medic.hpp"
#include "sources/Virologist.hpp"
#include <iostream>
using namespace std;
using namespace pandemic;

int main() {
    Board b;
    Scientist s(b,City::Algiers,4);
    s.take_card(City::Algiers).build();
    bool bo=b.have_research_station(City::Algiers);
    cout<<bo<<endl;
    return 0;
}

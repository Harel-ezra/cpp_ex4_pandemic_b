#include "Researcher.hpp"
using namespace std;
using namespace pandemic;

const int five=5; // const number declere on 5

Researcher& Researcher::discover_cure(Color c)
{
    if(sum_color_cards(c)<five)
    {
        throw ("cant discover cure, no enough cards");
    }
    if(!board.have_cure(c))
    {
        remove_5_color_card(c);
        board.discover_cure(c);
    }
    return *this;
}


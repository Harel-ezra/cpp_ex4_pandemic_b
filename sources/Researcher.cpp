#include "Researcher.hpp"
using namespace std;
using namespace pandemic;

Researcher& Researcher::discover_cure(Color c)
{
    if(sum_color_cards(c)<5)
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


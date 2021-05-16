#include "Researcher.hpp"
using namespace std;
using namespace pandemic;

Researcher& Researcher::discover_cure(Color c)
{
    if(!board.have_cure(c) && sum_color_cards(c)>=5)
    {
        remove_5_color_card(c);
        board.discover_cure(c);
    }
    return *this;
}


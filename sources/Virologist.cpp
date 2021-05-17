#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

Virologist& Virologist::treat(City c)
{
    if(c==this->city)
    {
        Player::treat(c);
        return *this;
    }
    if(0==board.disease_level(c))
    {
        throw ("cant treat cure, no cure in the city");
    }
    for(City city: player_cards)
    {
        if(city==c)
        {
            if (board.have_cure(board.color_of_city(c)))
            {
                board[c] = 0;
            }
            else
            {
                board[c] = board.disease_level(c) - 1;
            }
            player_cards.erase(city);
            return *this;
        }
    }
    throw ("cant treat cure, no have the match card for Virologist ");
}
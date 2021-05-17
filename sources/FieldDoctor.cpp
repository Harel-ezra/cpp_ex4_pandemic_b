#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

FieldDoctor& FieldDoctor::treat(City c)
{
    if(this->city==c)
    {
        Player::treat(c);
        return *this;
    }
    if(!board.has_neighbors(this->city,c))
    {
        throw ("cant treat cure, too far..");
    }
    if(0==board.disease_level(c))
    {
        throw ("cant treat cure, no cure in the city");
    }
    if(board.have_cure(board.color_of_city(c)))
    {
        board[c]=0;
    }
    else
    {
        board[c]=board.disease_level(c)-1;
        //board.disease_level(this->city)-=1;

    }
    return *this;
}

#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

FieldDoctor& FieldDoctor::treat(City c)
{
    if(this->city!=c && !board.has_neighbors(this->city,c))
    {
        throw ("cant treat cure, too far..");
    }
    if(0==board.disease_level(c))
    {
        throw ("cant treat cure, no cure in the city");
    }
    if(board.have_cure(board.color_of_city(this->city)))
    {
        board[this->city]=0;
    }
    else
    {
        board[this->city]=board.disease_level(this->city)-1;
    }
    return *this;
}

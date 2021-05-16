#include "Medic.hpp"
using namespace std;
using namespace pandemic;


Medic& Medic::drive(City c)
{
    try {
        Player::drive(c);
        if(board.have_cure(board.color_of_city(c)))
        {
            board[c]=0;
        }
        return *this;
    }
    catch (...)
    {
        throw ("cant drive to this city, the are not a neighbors");
    }
}
Medic& Medic::fly_direct (City c)
{
    try {
        Player::fly_direct(c);
        if(board.have_cure(board.color_of_city(c)))
        {
            board[c]=0;
        }
        return *this;
    }
    catch (...)
    {
        throw ("cant drive to this city, no have the match card");
    }
}
Medic& Medic::fly_charter(City c)
{
    try {
        Player::fly_charter(c);
        if(board.have_cure(board.color_of_city(c)))
        {
            board[c]=0;
        }
        return *this;
    }
    catch (...)
    {
        throw ("cant drive to this city, no have the match card");
    }
}
Medic& Medic::fly_shuttle(City c)
{
    try {
        Player::fly_shuttle(c);
        if(board.have_cure(board.color_of_city(c)))
        {
            board[c]=0;
        }
        return *this;
    }
    catch (...)
    {
        throw ("cant drive to this city, no have research_station in both, src and dest");
    }
}
Medic& Medic::treat(City c)
{
    if(0==board.disease_level(this->city))
    {
        throw ("cant treat cure, no cure in the city");
    }
    board[this->city]=0;
    return *this;
}

#include "Player.hpp"
using namespace std;
using namespace pandemic;

void Player::same_city_exaeption(City c1, City c2)
{
    if(c1==c2)
        throw ("cant drive to this city, is there");
}

Player& Player::drive(City c)
{
    same_city_exaeption(this->city,c);
    if(! this->board.has_neighbors(this->city,c))
    {
        throw ("cant drive to this city, the are not a neighbors");
    }
    this->city=c;
    return *this;
}
Player& Player::fly_direct (City c)
{
    same_city_exaeption(this->city,c);
    if(player_cards.find(c)==player_cards.end())
    {
        throw ("cant drive to this city, no have the match card");
    }
    player_cards.erase(c);
    this->city=c;
    return *this;
}

Player& Player::fly_charter(City c)
{
    same_city_exaeption(this->city,c);
    if(player_cards.find(this->city)==player_cards.end())
    {
        throw ("cant drive to this city, no have the match card");
    }
    player_cards.erase(this->city);
    this->city=c;
    return *this;
}
Player& Player::fly_shuttle(City c)
{
    if(!board.have_research_station(this->city) || !board.have_research_station(c) )
    {
        throw ("cant drive to this city, no have research_station in both, src and dest");
    }
    this->city=c;
    return *this;
}
Player& Player::build()
{
    if(player_cards.find(this->city)==player_cards.end())
    {
        throw ("cant build a new research_station, no have fit card");
    }
    if(!board.have_research_station(this->city) )
    {
        board.build_research_station(this->city);
        player_cards.erase(this->city);
    }
    return *this;
}
int Player::sum_color_cards(Color c)
{
    int sum=0;
    for (City city: player_cards)
    {
        if(board.color_of_city(city)==c)
        {
            sum++;
        }
    }
    return sum;
}
void Player::remove_5_color_card(Color c)
{
    int sum=0;
    for (City city: player_cards)
    {
        if(board.color_of_city(city)==c)
        {
            player_cards.erase(city);
            sum++;
        }
        if(5==sum)
        {
            return;
        }
    }
}


Player& Player::discover_cure(Color c)
{
    if(!board.have_research_station(this->city))
    {
        throw ("cant discover cure, no have research station in the city");
    }
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
Player& Player::treat(City c)
{
    if(0==board.disease_level(this->city))
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
Player& Player::take_card(City  c)
{
    player_cards.insert(c);
    return *this;
}
std::string Player::role()
{
    return "*this";
}
Player& Player::remove_cards()
{
    player_cards={};
    return *this;
}

#include "Board.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <set>

using namespace std;
using namespace pandemic;

int& Board::operator[](City c) {
    return board_game.find(c)->second.disease_level;
}

//const int Board::operator[](City c) const
//{
//    return board_game.find(c)->second.disease_level;
//}

bool Board::is_clean() const {
    for(const auto &city:board_game)
    {
        if(city.second.disease_level != 0)
        {
            return false;
        }
    }
    return true;
}

void Board::remove_cures()
{
    cure_is_discover.Black= false;
    cure_is_discover.Blue= false;
    cure_is_discover.Red= false;
    cure_is_discover.Yellow= false;
}
void Board::remove_stations()
{
    for(pair<City,city_info> city:board_game)
    {
        city.second.research_station= false;
    }
}

Color Board::color_of_city(City c)
{
    return board_game.find(c)->second.color;
}
bool Board::has_neighbors(City src, City dest) const
{
    return !(board_game.find(src)->second.neighbors.find(dest)==board_game.find(src)->second.neighbors.end());
}
bool Board::have_research_station(City c) const
{
    return board_game.find(c)->second.research_station;
}
void Board::build_research_station(City c)
{
    board_game.find(c)->second.research_station= true;
}

void Board::discover_cure(Color c)
{
    switch (c) {
        case Color::Yellow:
            cure_is_discover.Yellow= true;
            break;
        case Color::Red:
            cure_is_discover.Red= true;
            break;
        case Color::Blue:
            cure_is_discover.Blue= true;
            break;case Color::Black:
            cure_is_discover.Black= true;
            break;
    }
}

bool Board::have_cure(Color c) const
{
    switch (c) {
        case Color::Yellow:
            return cure_is_discover.Yellow;
        case Color::Red:
            return cure_is_discover.Red;
        case Color::Blue:
            return cure_is_discover.Blue;
            case Color::Black:
            return cure_is_discover.Black;
    }
}


int Board::disease_level(City c) //return the disease_level of the city
{
    return board_game.find(c)->second.disease_level;
}

std::ostream &pandemic::operator<<(std::ostream &output, const Board &board) {
    return output;
}
void Board::init()
{
    board_game = {
            {City::Algiers,(city_info){City::Algiers,Color::Black,set<City>{City::Madrid, City::Paris, City::Istanbul, City::Cairo},0,false}},
            {City::Atlanta,(city_info){City::Atlanta,Color::Blue,set<City>{City::Chicago, City::Miami, City::Washington},0,false}},
            {City::Baghdad,(city_info){City::Baghdad,Color::Black,set<City>{City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi},0,false}},
            {City::Bangkok,(city_info){City::Bangkok,Color::Red,set<City>{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong},0,false}},
            {City::Beijing,(city_info){City::Beijing,Color::Red,set<City>{City::Shanghai, City::Seoul},0,false}},
            {City::Bogota,(city_info){City::Bogota,Color::Yellow,set<City>{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires},0,false}},
            {City::BuenosAires,(city_info){City::BuenosAires,Color::Yellow,set<City>{City::Bogota, City::SaoPaulo},0,false}},
            {City::Cairo,(city_info){City::Cairo,Color::Black,set<City>{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh},0,false}},
            {City::Chennai,(city_info){City::Chennai,Color::Black,set<City>{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta},0,false}},
            {City::Chicago,(city_info){City::Chicago,Color::Blue,set<City>{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal},0,false}},
            {City::Delhi,(city_info){City::Delhi,Color::Black,set<City>{City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata},0,false}},
            {City::Essen,(city_info){City::Essen,Color::Blue,set<City>{City::London, City::Paris, City::Milan, City::StPetersburg},0,false}},
            {City::HoChiMinhCity,(city_info){City::HoChiMinhCity,Color::Red,set<City>{City::Jakarta, City::Bangkok, City::HongKong, City::Manila},0,false}},
            {City::HongKong,(city_info){City::HongKong,Color::Red,set<City>{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei},0,false}},
            {City::Istanbul,(city_info){City::Istanbul,Color::Black,set<City>{City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow},0,false}},
            {City::Jakarta,(city_info){City::Jakarta,Color::Red,set<City>{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney},0,false}},
            {City::Johannesburg,(city_info){City::Johannesburg,Color::Yellow,set<City>{City::Kinshasa, City::Khartoum},0,false}},
            {City::Karachi,(city_info){City::Karachi,Color::Black,set<City>{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi},0,false}},
            {City::Khartoum,(city_info){City::Khartoum,Color::Yellow,set<City>{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg},0,false}},
            {City::Kinshasa,(city_info){City::Kinshasa,Color::Yellow,set<City>{City::Lagos, City::Khartoum, City::Johannesburg},0,false}},
            {City::Kolkata,(city_info){City::Kolkata,Color::Black,set<City>{City::Delhi, City::Chennai, City::Bangkok, City::HongKong},0,false}},
            {City::Lagos,(city_info){City::Lagos,Color::Yellow,set<City>{City::SaoPaulo, City::Khartoum, City::Kinshasa},0,false}},
            {City::Lima,(city_info){City::Lima,Color::Yellow,set<City>{City::MexicoCity, City::Bogota, City::Santiago},0,false}},
            {City::London,(city_info){City::London,Color::Blue,set<City>{City::NewYork, City::Madrid, City::Essen, City::Paris},0,false}},
            {City::LosAngeles,(city_info){City::LosAngeles,Color::Yellow,set<City>{City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney},0,false}},
            {City::Madrid,(city_info){City::Madrid,Color::Blue,set<City>{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers},0,false}},
            {City::Manila,(city_info){City::Manila,Color::Red,set<City>{City::HongKong, City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney},0,false}},
            {City::MexicoCity,(city_info){City::MexicoCity,Color::Yellow,set<City>{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota},0,false}},
            {City::Miami,(city_info){City::Miami,Color::Yellow,set<City>{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota},0,false}},
            {City::Milan,(city_info){City::Milan,Color::Blue,set<City>{City::Essen, City::Paris, City::Istanbul},0,false}},
            {City::Montreal,(city_info){City::Montreal,Color::Blue,set<City>{City::Chicago, City::Washington, City::NewYork},0,false}},
            {City::Moscow,(city_info){City::Moscow,Color::Black,set<City>{City::StPetersburg, City::Istanbul, City::Tehran},0,false}},
            {City::Mumbai,(city_info){City::Mumbai,Color::Black,set<City>{City::Karachi, City::Delhi, City::Chennai},0,false}},
            {City::NewYork,(city_info){City::NewYork,Color::Blue,set<City>{City::Montreal, City::Washington, City::London, City::Madrid},0,false}},
            {City::Osaka,(city_info){City::Osaka,Color::Red,set<City>{City::Taipei, City::Tokyo},0,false}},
            {City::Paris,(city_info){City::Paris,Color::Blue,set<City>{City::Algiers, City::Essen, City::Madrid, City::Milan, City::London},0,false}},
            {City::Riyadh,(city_info){City::Riyadh,Color::Black,set<City>{City::Baghdad, City::Cairo, City::Karachi},0,false}},
            {City::SanFrancisco,(city_info){City::SanFrancisco,Color::Blue,set<City>{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila},0,false}},
            {City::Santiago,(city_info){City::Santiago,Color::Yellow,set<City>{City::Lima},0,false}},
            {City::SaoPaulo,(city_info){City::SaoPaulo,Color::Yellow,set<City>{City::Bogota, City::BuenosAires, City::Lagos, City::Madrid},0,false}},
            {City::Seoul,(city_info){City::Seoul,Color::Red,set<City>{City::Beijing, City::Shanghai, City::Tokyo},0,false}},
            {City::Shanghai,(city_info){City::Shanghai,Color::Red,set<City>{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo},0,false}},
            {City::StPetersburg,(city_info){City::StPetersburg,Color::Blue,set<City>{City::Essen, City::Istanbul, City::Moscow},0,false}},
            {City::Sydney,(city_info){City::Sydney,Color::Red,set<City>{City::Jakarta, City::Manila, City::LosAngeles},0,false}},
            {City::Taipei,(city_info){City::Taipei,Color::Red,set<City>{City::Shanghai, City::HongKong, City::Osaka, City::Manila},0,false}},
            {City::Tehran,(city_info){City::Tehran,Color::Black,set<City>{City::Baghdad, City::Moscow, City::Karachi, City::Delhi},0,false}},
            {City::Tokyo,(city_info){City::Tokyo,Color::Red,set<City>{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco},0,false}},
            {City::Washington,(city_info){City::Washington,Color::Blue,set<City>{City::Atlanta, City::NewYork, City::Montreal, City::Miami},0,false}}};
}

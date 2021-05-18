#include "Dispatcher.hpp"
using namespace pandemic;

Dispatcher &Dispatcher::fly_direct(pandemic::City city)
{
    if (this->cityNow == city)
    {
        string exp = "you can't fly from city to itself";
        throw exp;
    }

    if (this->board.get_board()[this->cityNow].get_Station())
    {
        this->cityNow = city;
    }
    else
    {
        Player::fly_direct(city);
    }
    return *this;
}

string Dispatcher::role(){
    return this->vox;
}
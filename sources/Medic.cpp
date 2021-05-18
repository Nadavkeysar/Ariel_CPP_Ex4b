#include "Medic.hpp"
using namespace pandemic;

Medic &Medic::treat(pandemic::City city)
{
    if (this->cityNow != city)
    {
        string exp = "you are not in " + to_string(city);
        throw exp;
    }

    if (this->board[city] == 0)
    {
        string exp = to_string(city) + " is not sick";
        throw exp;
    }
    this->board[city] = 0;

    return *this;
}

Medic &Medic::drive(pandemic::City city)
{
    Player::drive(city);
    pandemic::Color c = this->board.get_board()[city].get_Color();
    if (this->board.get_madicines(c))
    {
        this->board[city] = 0;
    }
    return *this;
}

Medic &Medic::fly_direct(pandemic::City city)
{
    Player::fly_direct(city);
    pandemic::Color c = this->board.get_board()[city].get_Color();
    if (this->board.get_madicines(c))
    {
        this->board[city] = 0;
    }
    return *this;
}

Medic &Medic::fly_charter(pandemic::City city)
{
    Player::fly_charter(city);
    pandemic::Color c = this->board.get_board()[city].get_Color();
    if (this->board.get_madicines(c))
    {
        this->board[city] = 0;
    }
    return *this;
}

Medic &Medic::fly_shuttle(pandemic::City city)
{
    Player::fly_shuttle(city);
    pandemic::Color c = this->board.get_board()[city].get_Color();
    if (this->board.get_madicines(c))
    {
        this->board[city] = 0;
    }
    return *this;
}

string Medic::role()
{
    return this->vox;
}
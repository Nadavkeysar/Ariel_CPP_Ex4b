#include "FieldDoctor.hpp"
using namespace pandemic;

FieldDoctor &FieldDoctor::treat(pandemic::City city)
{
    list<pandemic::City> &fd = this->board.get_board()[this->cityNow].get_neighbors();
    if (this->cityNow == city || find(fd.begin(), fd.end(), city) != fd.end())
    {
        if (this->board[city] == 0)
        {
            string exp = to_string(city) + " isn't sick";
            throw exp;
        }

        pandemic::Color c = this->board.get_board()[city].get_Color();
        if (this->board.get_madicines(c))
        {
            this->board[city] = 0;
        }
        else
        {
            this->board[city]--;
        }
    }
    else
    {
        string exp = "you can't treat " + to_string(city);
        throw exp;
    }

    return *this;
}

string FieldDoctor::role()
{
    return this->vox;
}
#include "Virologist.hpp"
using namespace pandemic;

Virologist &Virologist::treat(pandemic::City city)
{
    auto card = find(this->cards.begin(), this->cards.end(), city);
    if (this->cityNow != city && (card == this->cards.end()))
    {
        string exp = "you don't have card of " + to_string(city);
        throw exp;
    }

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
    
    if (this->cityNow != city)
    {
        this->cards.erase(card);
    }

    return *this;
}

string Virologist::role()
{
    return this->vox;
}
#include "Scientist.hpp"
using namespace pandemic;

Scientist &Scientist::discover_cure(pandemic::Color color)
{
    bool researches = this->board.get_board()[this->cityNow].get_Station();
    if (!researches)
    {
        string exp = "you don't in research station";
        throw exp;
    }

    bool cure = this->board.get_madicines(color);
    int counter_cards = 0;
    for (auto itr : this->cards)
    {
        if (this->board.get_board()[itr].get_Color() == color)
        {
            counter_cards++;
        }
    }

    if (counter_cards >= this->howMachCards)
    {
        if (!cure)
        {
            counter_cards = this->howMachCards;
            for (auto itr = this->cards.begin(); itr != this->cards.end() && counter_cards > 0;)
            {
                if (this->board.get_board()[*itr].get_Color() == color)
                {
                    itr = this->cards.erase(itr);
                    counter_cards--;
                }
                else
                {
                    ++itr;
                }
            }
            this->board.set_madicines(color, true);
        }
    }
    else
    {
        string exp = "you don't have enough cards";
        throw exp;
    }

    return *this;
}

string Scientist::role()
{
    return this->vox;
}
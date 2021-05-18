#include "Researcher.hpp"
using namespace pandemic;

Researcher &Researcher::discover_cure(pandemic::Color color)
{
    bool cure = this->board.get_madicines(color);

    int counter_cards = 0;
    for (auto itr: this->cards)
    {
        if (this->board.get_board()[itr].get_Color() == color)
        {
            counter_cards++;
        }
    }

    if (counter_cards >= CARDS_CURE)
    {
        if (!cure)
        {
            counter_cards = CARDS_CURE;
            for ( auto itr = this->cards.begin(); itr != this->cards.end() && counter_cards > 0;)
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

string Researcher::role()
{
    return this->vox;
}
#include "GeneSplicer.hpp"
using namespace pandemic;

GeneSplicer &GeneSplicer::discover_cure(pandemic::Color color)
{
    bool researches = this->board.get_board()[this->cityNow].get_Station();
    if (!researches)
    {
        string exp = "you don't in research station";
        throw exp;
    }

    bool cure = this->board.get_madicines(color);
    int counter_cards = this->cards.size();

    if (counter_cards >= CARDS_CURE)
    {
        if (!cure)
        {
            counter_cards = CARDS_CURE;
            for (auto itr = this->cards.begin(); itr != this->cards.end() && counter_cards > 0;)
            {
                itr = this->cards.erase(itr);
                counter_cards--;
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

string GeneSplicer::role()
{
    return this->vox;
}
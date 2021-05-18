#include "Player.hpp"
using namespace pandemic;

Player &Player::drive(pandemic::City city)
{
    if (this->cityNow == city)
    {
        string exp = "you can't fly from city to itself";
        throw exp;
    }

    list<pandemic::City> &nei = this->board.get_board()[this->cityNow].get_neighbors();
    if (find(nei.begin(), nei.end(), city) != nei.end())
    {
        this->cityNow = city;
    }
    else
    {
        string exp = "you can't drive to " + to_string(city);
        throw exp;
    }
    return *this;
}

Player &Player::fly_direct(pandemic::City city)
{
    if (this->cityNow == city)
    {
        string exp = "you can't fly from city to itself";
        throw exp;
    }

    auto card = find(this->cards.begin(), this->cards.end(), city);
    if (card != this->cards.end())
    {
        this->cityNow = city;
        this->cards.erase(card);
    }
    else
    {
        string exp = "you can't fly to " + to_string(city);
        throw exp;
    }
    return *this;
}

Player &Player::fly_charter(pandemic::City city)
{
    if (this->cityNow == city)
    {
        string exp = "you can't fly from city to itself";
        throw exp;
    }

    auto card = find(this->cards.begin(), this->cards.end(), this->cityNow);
    if (card != this->cards.end())
    {
        this->cityNow = city;
        this->cards.erase(card);
    }
    else
    {
        string exp = "you can't fly to " + to_string(city);
        throw exp;
    }
    return *this;
}

Player &Player::fly_shuttle(pandemic::City city)
{
    if (this->cityNow == city)
    {
        string exp = "you can't fly from city to itself";
        throw exp;
    }

    if (this->board.get_board()[this->cityNow].get_Station() && this->board.get_board()[city].get_Station())
    {
        this->cityNow = city;
    }
    else
    {
        string exp = "you can't fly to " + to_string(city);
        throw exp;
    }

    return *this;
}

Player &Player::build()
{
    if (!this->board.get_board()[this->cityNow].get_Station())
    {
        auto card = find(this->cards.begin(), this->cards.end(), this->cityNow);
        if (card != this->cards.end())
        {
            this->board.get_board()[this->cityNow].set_Station(true);
            this->cards.erase(card);
        }
        else
        {
            string exp = "you can't build research station";
            throw exp;
        }
    }
    return *this;
}

Player &Player::discover_cure(pandemic::Color color)
{
    bool researches = this->board.get_board()[this->cityNow].get_Station();
    if (!researches)
    {
        string exp = "you don't in research station";
        throw exp;
    }

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

Player &Player::treat(pandemic::City city)
{
    if (this->cityNow != city)
    {
        string exp = "you aren't in " + to_string(city);
        throw exp;
    }

    if (this->board[city] == 0)
    {
        string exp = "this city isn't sick";
        throw exp;
    }

    if (this->board.get_madicines(this->board.get_board()[city].get_Color()))
    {
        this->board[city] = 0;
    }
    else
    {
        this->board[city]--;
    }

    return *this;
}

Player &Player::take_card(pandemic::City city)
{
    this->cards.insert(city);
    return *this;
}

Player &Player::remove_cards()
{
    this->cards.clear();
    return *this;
}
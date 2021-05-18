#pragma once
#include <iostream>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
    class Player
    {
    protected:
        Board &board;
        City cityNow;
        set<pandemic::City> cards;
        const int CARDS_CURE = 5;

    public:
        Player(pandemic::Board &b, pandemic::City c) : board(b), cityNow(c){};
        ~Player(){};
        virtual Player &drive(pandemic::City city);
        virtual Player &fly_direct(pandemic::City city);
        virtual Player &fly_charter(pandemic::City city);
        virtual Player &fly_shuttle(pandemic::City city);
        virtual Player &build();
        virtual Player &discover_cure(pandemic::Color color);
        virtual Player &treat(pandemic::City city);
        virtual Player &take_card(pandemic::City city);
        Player &remove_cards();
    };
};
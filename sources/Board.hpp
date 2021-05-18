#pragma once
#include <iostream>
#include <list>
#include <map>
#include <array>
#include "City.hpp"
#include "Color.hpp"
using namespace pandemic;
using namespace std;

namespace pandemic
{
    class City_Data
    {
        pandemic::City city;
        pandemic::Color color;
        int diseases;
        bool station;
        list<pandemic::City> neighbors;

    public:
        City_Data(){};
        City_Data(const City c, const Color col, const int dis, const bool st, const list<pandemic::City> ne) : city(c), color(col), diseases(dis), station(st)
        {
            neighbors = ne;
        };
        ~City_Data(){};
        int &get_Diseases();
        int get_City() const;
        pandemic::Color get_Color() const;
        bool get_Station() const;
        void set_Station (bool station);
        list<pandemic::City> &get_neighbors();
        friend ostream &operator<<(ostream &os, const City_Data &c);
    };

    const int SIZE = 4;
    class Board
    {
        map<pandemic::City, City_Data> board_map;
        array<bool, SIZE> medicines;
        void loadCities();
        void blackCities();
        void yellowCities();
        void redCities();
        void blueCities();

    public:
        Board()
        {
            medicines = {false, false, false, false};
            loadCities();
        };
        ~Board(){};
        int &operator[](pandemic::City city);
        bool is_clean();
        void remove_cures();
        void remove_stations();
        map<pandemic::City, City_Data>& get_board();
        bool get_madicines(Color c) const;
        void set_madicines(Color color, bool med);
        friend ostream &operator<<(ostream &os, const Board &b);
    };
};
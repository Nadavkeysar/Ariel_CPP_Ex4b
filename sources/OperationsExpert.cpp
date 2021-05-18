#include "OperationsExpert.hpp"
using namespace pandemic;

OperationsExpert &OperationsExpert::build()
{
    this->board.get_board()[this->cityNow].set_Station(true);
    return *this;
}

string OperationsExpert::role()
{
    return this->vox;
}
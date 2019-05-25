#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <vector>


static const int SIZE = 8;

static const std::vector<std::pair<int, int>> DIRECTIONS = 
    {{-1, -1}, {0, -1}, {1, -1}, {-1, 0},
    {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

static const int X_OFFSET = 49;
static const int Y_OFFSET = 65;

#endif
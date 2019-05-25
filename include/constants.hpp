#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <vector>


static const int SIZE = 8;

static const std::vector<std::pair<int, int>> DIRECTIONS = 
    {{-1, -1}, {0, -1}, {1, -1}, {-1, 0},
    {1, 0}, {1, -1}, {1, 0}, {1, 1}};

#endif
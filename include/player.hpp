#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>

#include "constants.hpp"
#include "piece.hpp"


class Player {
    public:
        Player(char representation);
        bool has_valid_moves();
    
    private:
        std::vector<std::pair<int, int>> valid_moves;
        char representation;
};

#endif
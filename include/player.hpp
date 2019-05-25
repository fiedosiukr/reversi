#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>

#include "piece.hpp"


class Player {
    public:
        Player(char representation);
        bool has_valid_moves();
        char get_representation();
        void clear_valid_moves();
        void add_valid_move(int x, int y);
        bool is_in_valid_moves(int x, int y);
        
    private:
        std::vector<std::pair<int, int>> valid_moves;
        char representation;
};

#endif
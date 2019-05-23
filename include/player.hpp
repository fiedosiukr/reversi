#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>

#include "board.hpp"

class Player {
    public:
        Player(char piece);
        void calculate_valid_moves(Board* board);
        bool has_valid_moves();
        void render_piece();
    
    private:
        std::vector<std::pair<int, int>> valid_moves;
        char piece;
};

#endif
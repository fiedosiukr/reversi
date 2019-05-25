#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include "piece.hpp"
#include "constants.hpp"
#include "player.hpp"

class Piece;

class PlayState {
    public:
        PlayState();
        void render();

    private:
        Piece* pieces[SIZE * SIZE];

        Player* white_player;
        Player* black_player;
        Player* active_player;

        bool add_piece(int x, int y);
        void change_pieces(int x, int y);
        bool is_valid_move(int x, int y);
        bool is_on_board(int x, int y);
        void calculate_valid_moves(Player* player);
};

#endif
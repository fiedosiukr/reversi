#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include "piece.hpp"
#include "constants.hpp"


class PlayState {
    public:
        PlayState();
        void render();

    private:
        Piece* pieces[SIZE * SIZE];

};

#endif
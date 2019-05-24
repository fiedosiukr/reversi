#include <iostream>

#include "../include/playstate.hpp"


int main() {
    PlayState* play_state;
    play_state = new PlayState();


    play_state->render();
    return 0;
}
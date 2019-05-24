#include "../include/player.hpp"

#include <iostream>


Player::Player(char representation) {
    this->representation = representation;
}

bool Player::has_valid_moves() {
    return (valid_moves.size() > 0);
}
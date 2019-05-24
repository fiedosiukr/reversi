#include "../include/player.hpp"

#include <iostream>


Player::Player(char representation) {
    this->representation = representation;
}

char Player::get_representation() {
    return representation;
}

bool Player::has_valid_moves() {
    return (valid_moves.size() > 0);
}
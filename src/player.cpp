#include "../include/player.hpp"

#include <iostream>


Player::Player(char piece) {
    this->piece = piece;
}

void Player::calculate_valid_moves(Board* board) {

}

bool Player::has_valid_moves() {
    return (valid_moves.size() > 0);
}

void Player::render_piece() {
    std::cout << piece;
}
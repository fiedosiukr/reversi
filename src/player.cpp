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

void Player::clear_valid_moves() {
    valid_moves.clear();
}

void Player::add_valid_move(int x, int y) {
    valid_moves.emplace_back(std::make_pair(x, y));
}

bool Player::is_in_valid_moves(int x, int y) {
    std::pair<int, int> pair = std::make_pair(x, y);
    for (int i = 0; i < valid_moves.size(); i++) {
        if (valid_moves[i] == pair)
            return true;
    }
    
    return false;
}
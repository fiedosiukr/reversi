#include "../include/piece.hpp"

#include <iostream>


Piece::Piece(char representation) {
    this->representation = representation;
}

char Piece::get_representation() {
    return representation;
}

void Piece::render() {
    std::cout << representation;
}

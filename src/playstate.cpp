#include "../include/playstate.hpp"

#include <iostream>


PlayState::PlayState() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            pieces[j * SIZE + i] = nullptr;
        }
    }
}

void PlayState::render() {
    for (int i = 0; i < SIZE; i++) {
        std::cout << (char)('A' + i) << "|";
        for (int j = 0; j < SIZE; j++) {
            if (pieces[i * SIZE + j] == nullptr)
                std::cout << "-";
            else
                pieces[i * SIZE +j]->render();
            std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "  1 2 3 4 5 6 7 8\n";
}
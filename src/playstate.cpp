#include "../include/playstate.hpp"

#include <iostream>


PlayState::PlayState() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            pieces[i * SIZE + j] = nullptr;
        }
    }
    white_player = new Player('O');
    black_player = new Player('X');
    active_player = white_player;

    pieces[3 * SIZE + 3] = new Piece(white_player->get_representation());
    pieces[4 * SIZE + 4] = new Piece(white_player->get_representation());
    pieces[3 * SIZE + 4] = new Piece(black_player->get_representation());
    pieces[4 * SIZE + 3] = new Piece(black_player->get_representation());

    calculate_valid_moves(active_player);
}

void PlayState::render() {
    for (int i = 0; i < SIZE; i++) {
        std::cout << (char)('A' + i) << "|";
        for (int j = 0; j < SIZE; j++) {
            if (pieces[i * SIZE + j] == nullptr)
                std::cout << "-";
            else
                pieces[i * SIZE + j]->render();
            std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "  1 2 3 4 5 6 7 8\n";
}

bool PlayState::is_valid_move(int x, int y) {
    if (!is_on_board(x, y))
        return false;

    int currentX, currentY;
    bool piece_between;
    for (int i = 0; i < DIRECTIONS.size(); i++) {
        currentX = x + DIRECTIONS[i].first;
        currentY = y + DIRECTIONS[i].second;
        piece_between = false;
        while (is_on_board(currentX, currentY)) {
            if (pieces[currentY * SIZE + currentX] == nullptr)
                break;
            else if (pieces[currentY * SIZE + currentX]->get_representation() != active_player->get_representation()) {
                piece_between = true;
                currentX += DIRECTIONS[i].first;
                currentY += DIRECTIONS[i].second;
            } else {
                if (piece_between)
                    return true;
                else
                    break;
            }
        }
    }

    return false;
}

bool PlayState::is_on_board(int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}

void PlayState::calculate_valid_moves(Player*  player) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (pieces[j * SIZE + i] != nullptr)
                continue;
            
            if (is_valid_move(i, j))
                player->add_valid_move(i, j);
        }
    }
}


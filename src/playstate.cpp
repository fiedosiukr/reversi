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

bool PlayState::add_piece(int x, int y) {
    if (!is_valid_move(x, y))
        return false;

    pieces[y * SIZE + x] = new Piece(active_player->get_representation());
    change_pieces(x, y);
    return true;
}

void PlayState::change_pieces(int x, int y) {
    std::pair<int, int> current_pos;
    std::vector<std::pair<int, int>> pieces_to_change;
    for (int i = 0; i < DIRECTIONS.size(); i++) {
        current_pos.first = x + DIRECTIONS[i].first;
        current_pos.second = y + DIRECTIONS[i].second;
        pieces_to_change.clear();
        while (is_on_board(current_pos.first, current_pos.second))
            if (pieces[current_pos.second * SIZE + current_pos.first] == nullptr)
                break;
            else if (pieces[current_pos.second * SIZE + current_pos.first]->get_representation() != active_player->get_representation()) {
                pieces_to_change.emplace_back(current_pos);
                current_pos.first += DIRECTIONS[i].first;
                current_pos.second += DIRECTIONS[i].second;
            } else {
                for (int i = 0; i < pieces_to_change.size(); i++) {
                    delete pieces[pieces_to_change[i].second * SIZE + pieces_to_change[i].first];
                    pieces[pieces_to_change[i].second * SIZE + pieces_to_change[i].first] =
                        new Piece(active_player->get_representation());
                }
                break;
            }
    }
}

bool PlayState::is_valid_move(int x, int y) {
    if (!is_on_board(x, y))
        return false;

    std::pair<int, int> current_pos;
    bool piece_between;
    for (int i = 0; i < DIRECTIONS.size(); i++) {
        current_pos.first = x + DIRECTIONS[i].first;
        current_pos.second = y + DIRECTIONS[i].second;
        piece_between = false;
        while (is_on_board(current_pos.first, current_pos.second)) {
            if (pieces[current_pos.second * SIZE + current_pos.first] == nullptr)
                break;
            else if (pieces[current_pos.second * SIZE + current_pos.first]->get_representation() != active_player->get_representation()) {
                piece_between = true;
                current_pos.first += DIRECTIONS[i].first;
                current_pos.second += DIRECTIONS[i].second;
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


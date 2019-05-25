#include "../include/playstate.hpp"

#include <iostream>
#include <cstdlib>


PlayState::PlayState() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            pieces[j * SIZE + i] = nullptr;
        }
    }
    white_player = new Player('O');
    black_player = new Player('X');
    active_player = white_player;

    pieces[3 * SIZE + 3] = new Piece(white_player->get_representation());
    pieces[4 * SIZE + 4] = new Piece(white_player->get_representation());
    pieces[3 * SIZE + 4] = new Piece(black_player->get_representation());
    pieces[4 * SIZE + 3] = new Piece(black_player->get_representation());
    num_whites = num_blacks = 2;

    calculate_valid_moves(active_player);
    game_end = false;
}

void PlayState::run() {
    while (!game_end) {
        render();
        ask_for_piece();
    }
}

void PlayState::render() {
    std::cout << "Number of whites: " << num_whites << ".\n";
    std::cout << "Number of blacks: " << num_blacks << ".\n";
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
    std::cout << "  1 2 3 4 5 6 7 8\n\n";
}

void PlayState::ask_for_piece() {
    std::cout << "It's " << active_player->get_representation() << " move.\n";
    
    while (true) {
        std::cout << "Enter coordinates of tile where you want to place a piece (C2, E7, etc.):";
        std::string input;
        std::cin >> input;
        if (input.length() <= 2 && input.length() > 0) {
            char x = input[1];
            char y = input[0];
            int i = (int)(x - X_OFFSET);
            int c = (int)(y - Y_OFFSET);
            if (is_on_board(i, c))
                if (add_piece(i, c))
                    break;
        }
        std::cout << "Provide a valid move!\n";
    }
}

bool PlayState::add_piece(int x, int y) {
    if (!active_player->is_in_valid_moves(x, y))
        return false;
    
    pieces[y * SIZE + x] = new Piece(active_player->get_representation());
    active_player == white_player ? ++num_whites : ++num_blacks;
    change_pieces(x, y);
    change_active_player();
    return true;
}

void PlayState::change_pieces(int x, int y) {
    std::pair<int, int> current_pos;
    std::vector<std::pair<int, int>> pieces_to_change;
    for (auto direction : DIRECTIONS) {
        current_pos.first = x + direction.first;
        current_pos.second = y + direction.second;
        pieces_to_change.clear();
        while (is_on_board(current_pos.first, current_pos.second))
            if (pieces[current_pos.second * SIZE + current_pos.first] == nullptr)
                break;
            else if (pieces[current_pos.second * SIZE + current_pos.first]->get_representation() != active_player->get_representation()) {
                pieces_to_change.emplace_back(current_pos);
                current_pos.first += direction.first;
                current_pos.second += direction.second;
            } else {
                for (int i = 0; i < pieces_to_change.size(); i++) {
                    delete pieces[pieces_to_change[i].second * SIZE + pieces_to_change[i].first];
                    pieces[pieces_to_change[i].second * SIZE + pieces_to_change[i].first] =
                        new Piece(active_player->get_representation());
                    active_player == white_player ? (++num_whites, --num_blacks) : (++num_blacks, --num_whites);
                }
                break;
            }
    }
}

bool PlayState::is_on_board(int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}

void PlayState::change_active_player() {
    active_player = active_player == white_player ? black_player : white_player;
    active_player->clear_valid_moves();
    calculate_valid_moves(active_player);

    if (!active_player->has_valid_moves()) {
        active_player = active_player == white_player ? black_player : white_player;
        calculate_valid_moves(active_player);
        if (!active_player->has_valid_moves()) { 
            end_game();
        }
    }
}

void PlayState::end_game() {
    std::cout << "The game is over ";
    if (num_whites > num_blacks)
        std::cout << "and white is the winner with " << num_whites - num_blacks << "more pieces.";
    else if (num_whites > num_blacks)
        std::cout << "and black is the winner with " << num_blacks - num_whites << "more pieces.";
    else
        std::cout << "and it has ended with a draw.";
    
    game_end = true;
}

bool PlayState::is_valid_move(int x, int y) {
    if (!is_on_board(x, y))
        return false;

    std::pair<int, int> current_pos;
    bool piece_between;
    for (auto directions : DIRECTIONS) {
        current_pos.first = x + directions.first;
        current_pos.second = y + directions.second;
        piece_between = false;
        while (is_on_board(current_pos.first, current_pos.second)) {
            if (pieces[current_pos.second * SIZE + current_pos.first] == nullptr)
                break;
            else if (pieces[current_pos.second * SIZE + current_pos.first]->get_representation() != active_player->get_representation()) {
                piece_between = true;
                current_pos.first += directions.first;
                current_pos.second += directions.second;
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


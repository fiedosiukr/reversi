#ifndef PIECE_HPP
#define PIECE_HPP

class Piece {
    public:
        Piece(char representation);
        char get_representation();
        void render();
    
    private:
        char representation;
};

#endif
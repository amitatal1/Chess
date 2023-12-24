#pragma once
#include "Piece.h"
class Rook :
    public Piece
{
public:
    Rook(char type, bool color, int x, int y, Board& board);
    ~Rook();
    virtual bool IsMovePossible(int x, int y,bool threatSearch = false)  ; // checks if certain piece is able to go to move to a specific position 
};


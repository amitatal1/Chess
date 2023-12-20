#pragma once
#include "Piece.h"
class Knight :
    public Piece
{
    Knight(char type, bool color, int x, int y, Board* board);
    ~Knight();
};


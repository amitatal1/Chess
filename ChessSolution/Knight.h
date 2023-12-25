#pragma once
#include "Piece.h"
class Knight :
    public Piece
{
public:
    Knight(char type, bool color, int x, int y, Board& board);
    ~Knight();
    virtual bool IsMovePossible(int x, int y, bool threatSearch = false ) override  ;
};


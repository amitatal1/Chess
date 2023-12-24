#pragma once
#include "Piece.h"
class Queen :
    public Piece
{
    Queen(char type, bool color, int x, int y, Board& board);
    ~Queen();

    virtual bool IsMovePossible(int x, int y, bool threatSearch = false) override;
};


#pragma once
#include "Piece.h"
class Pawn :
    public Piece
{
public:
    Pawn(char type, bool color, int x, int y, Board& board);
    ~Pawn();

    virtual bool IsMovePossible(int x, int y)const override; // checks if certain piece is able to go to move to a specific position 
};


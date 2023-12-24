#pragma once
#include "Piece.h"
class King :
    public Piece
{
public:
    King(char type, bool color, int x, int y, Board& board);
    ~King();

   virtual bool IsMovePossible(int x, int y, bool threatSearch = false) override;
  
};


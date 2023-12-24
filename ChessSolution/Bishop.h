#pragma once
#include "Piece.h"
class Bishop :
    public Piece
{
public:
    Bishop(char type, bool color, int x, int y, Board& board);
    ~Bishop();
    virtual bool IsMovePossible(int x, int y,  bool threatSearch = false)  ;

};


#pragma once
#include "Piece.h"
class Bishop :
    public Piece
{
public:
    virtual bool IsMovePossible(int x, int y) const override;

};


#include "Rook.h"

Rook::Rook(char type, bool color, int x, int y, Board& board)
    :Piece(type, color, x, y, board)
{
}

Rook::~Rook()
{
}



bool Rook::IsMovePossible(int x, int y, bool threatSearch = false) 
{
    if (x < 0 || y < 0 || x >= BOARD_DIMENSION || y >= BOARD_DIMENSION) // out of bounds 
    {
        return false;
    }

    if (_board[x][y] != nullptr && _board[x][y]->getColor() == _color)
    {
        // Destination is occupied by a piece of the same color
        return false;
    }

    if (!threatSearch && _board.wouldMoveCauseCheck(this, x, y))
    {
        return false;
    }
    
    if (_x== x || _y == y )// moving to the sides vertically
    {
        return true;
    }


    return false;
}



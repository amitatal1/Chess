#include "Rook.h"

Rook::Rook(char type, bool color, int x, int y, Board& board)
    :Piece(type, color, x, y, board)
{
}

Rook::~Rook()
{
}

bool Rook::IsMovePossible(int x, int y)
{
    if (x >= BOARD_DIMENSION || y >= BOARD_DIMENSION) // out of bounds 
    {
        return false;
    }

    if (_board[x][y] != nullptr && _board[x][y]->getColor() == _color)
    {
        // Destination is occupied by a piece of the same color
        return false;
    }

    
    if (_board[x][y] == nullptr && (_x== x || _y == y) )// moving to the sided 
    {
            return true;
    }


    return false;
}



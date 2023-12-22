#include "Bishop.h"

bool Bishop::IsMovePossible(int x, int y) const
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

 
    if (_x - x == _y - y) // moving diagonaly
    {
        return true;
    }
    

    return false;
}

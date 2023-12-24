#include "Queen.h"

Queen::Queen(char type, bool color, int x, int y, Board& board)
    : Piece(type,color,x,y,board)
{
}

Queen::~Queen()
{
}

bool Queen::IsMovePossible(int x, int y, bool threatSearch)
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

    int deltaX = std::abs(x - _x);
    int deltaY = std::abs(y - _y);

    // Queen can move horizontally, vertically, or diagonally
    if (deltaX == 0 || deltaY == 0 || deltaX == deltaY)
    {
        return true;
    }

    return false;
    
   }

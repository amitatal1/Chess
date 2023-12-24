#include "King.h"

King::King(char type, bool color, int x, int y, Board& board)
    :Piece(type,color,x,y,board)
{
   
}

King::~King()
{
}

bool King::IsMovePossible(int x, int y, bool threatSearch)
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

    // King can move one square in any direction
    if (deltaX <= 1 && deltaY <= 1)
    {
        return true;
    }

    return false;

}

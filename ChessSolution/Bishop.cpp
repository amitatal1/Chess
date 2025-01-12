#include "Bishop.h"

Bishop::Bishop(char type, bool color, int x, int y, Board& board)
: Piece(type,color,x,y,board)
{
}

Bishop::~Bishop()
{
}

bool Bishop::IsMovePossible(int x, int y, bool threatSearch)
{
    if (x < 0 || y < 0 || x >= BOARD_DIMENSION || y >= BOARD_DIMENSION) // out of bounds 
    {
        _board.setStatus(OUT_OF_BORDER);
        return false;
    }

    if (_board[x][y] != nullptr && _board[x][y]->getColor() == _color)
    {
        // Destination is occupied by a piece of the same color
        _board.setStatus(OCCUPIED_DESTINY);
        return false;
    }

    if (!IsPathClear(x, y))
    {
        _board.setStatus(ILLEGAL_MOVE);
        return false; // if path is occupied
    }


    if (!threatSearch && _board.wouldMoveCauseCheck(this, x, y))
    {
        _board.setStatus(SELF_CHECK);
        return false;
    }
 
    if (std::abs(_x - x) == std::abs(_y - y)) // moving diagonaly
    {
        return true;
    }
    _board.setStatus(ILLEGAL_MOVE);

    return false;
}
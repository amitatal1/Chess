#include "Knight.h"

Knight::Knight(char type, bool color, int x, int y, Board& board)
	:Piece(type, color, x, y, board)

{

}

Knight::~Knight()
{
}

bool Knight::IsMovePossible(int x, int y) const
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

    int deltaX = std::abs(x - _x);
    int deltaY = std::abs(y - _y);

    return (deltaX == 1 && deltaY == 2) || (deltaX == 2 && deltaY == 1);
}

#include "Piece.h"

Piece::Piece(int x, int y, Board* board, bool color, char type)
    : _x(x), _y(y), _board(board), _color(color), _type(type)
{
}

int Piece::getX() const
{
    return _x;
}

int Piece::getY() const
{
    return _y;
}

bool Piece::getColor() const
{
    return _color;
}

char Piece::getType() const
{
    return _type;
}

#include "Piece.h"

Piece::Piece(char type, bool color,int x, int y,Board& board)
    : _x(x), _y(y), _board(board), _color(color), _type(type)
{
}

Piece::~Piece()
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

void Piece::setPosition(int x, int y) 
{
    _x = x;
    _y = y;
}

bool Piece::getColor() const
{
    return _color;
}

char Piece::getType() const
{
    return _type;
}

bool Piece::move(int x, int y)
{
    if (IsMovePossible(x, y))
    {
        if (_board[x][y] != nullptr) //hit
        {
            delete(_board[_x][_y]);
        }

        _board[_x][_y] = nullptr;

        _board[x][y] = this;
        setPosition(x, y);
        return true;
    }
    return false;
}

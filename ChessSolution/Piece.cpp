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

bool Piece::IsPathClear(int destX, int destY) 
{
    //Calculate the direction of movement
    int deltaX=0, deltaY=0;

    //x direction
    if (destX > _x) 
    {
        deltaX = 1;
    }
    else if (destX < _x) {
        deltaX = -1;
    }
    else {
        deltaX = 0;
    }

    //y direction
    if (destY > _y) {
        deltaY = 1;
    }
    else if (destY < _y) {
        deltaY = -1;
    }
    else {
        deltaY = 0;
    }

    //Check each square along the path (excluding the destination)
    for (int i = _x + deltaX, j = _y + deltaY; i != destX || j != destY; i += deltaX, j += deltaY) 
    {
        // If any square along the path is occupied, return false
        if (_board[i][j] != nullptr) {
            return false;
        }
    }

    
    return true;
}

bool Piece::move(int x, int y)
{
    if (IsMovePossible(x, y))
    {
        if (_board[x][y] != nullptr) //hit
        {
            delete(_board[x][y]);
        }

        _board[_x][_y] = nullptr;

        _board[x][y] = this;
        setPosition(x, y);
        return true;
    }
    return false;
}

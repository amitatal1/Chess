#include "Pawn.h"

Pawn::Pawn(char type, bool color, int x, int y, Board& board)
	:Piece(type, color, x,y,board)
{
}

Pawn::~Pawn()
{
}

bool Pawn::IsMovePossible(int x,int y)
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

        if (_color == BLACK)
        {
            if (_board[x][y] == nullptr && _x + 1 == x && _y == y) // moving forward
            {
                return true;
            }
            else if (_board[x][y] != nullptr && _x + 1 == x && (_y + 1 == y || _y - 1 == y)) // hitting option
            {
                return true;
            }
        }

        if (_color == WHITE)
        {
            if (_board[x][y] == nullptr && _x - 1 == x && _y == y) // moving forward
            {
                return true;
            }
            else if (_board[x][y] != nullptr && _x - 1 == x && (_y + 1 == y || _y - 1 == y)) // hitting option
            {
                return true;
            }
        }       
        
        return false;
    
	}






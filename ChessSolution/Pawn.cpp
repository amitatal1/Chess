#include "Pawn.h"

Pawn::Pawn(char type, bool color, int x, int y, Board& board)
	:Piece(type, color, x,y,board), _hasMoved(false)
{

}

Pawn::~Pawn()
{
}

bool Pawn::IsMovePossible(int x,int y, bool threatSearch ) 
{
        bool possibility = false;
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

        if (_color == BLACK)
        {
            if (_board[x][y] == nullptr && _x + 1 == x && _y == y) // moving forward
            {
                possibility= true;
            }
            else if (_board[x][y] != nullptr && _x + 1 == x && (_y + 1 == y || _y - 1 == y)) // hitting option
            {
                possibility = true;
            }
            else if (_hasMoved == false && _board[x][y] == nullptr && _x + 2 == x && _y == y)
            {
                if (_board[x - 1][y]!=nullptr)
                {
                    return false; // piece  stands in his way
                }

                
                possibility = true;
                
            }
        }

        else if (_color == WHITE)
        {
            if (_board[x][y] == nullptr && _x - 1 == x && _y == y) // moving forward
            {
                possibility = true;
            }
            else if (_board[x][y] != nullptr && _x - 1 == x && (_y + 1 == y || _y - 1 == y)) // hitting option
            {
                possibility = true;
            }
            else if (_hasMoved == false && _board[x][y] == nullptr && _x - 2 == x && _y == y)
            {
                if (_board[x + 1][y] != nullptr)
                {
                    return false; // piece  stands in his way
                }
              
                possibility = true;

            }
        }       
        
        if (possibility && !threatSearch) // moving for the first time disables his ability to double-step
        {
            _hasMoved = true;
        }
        return possibility;
    
	}






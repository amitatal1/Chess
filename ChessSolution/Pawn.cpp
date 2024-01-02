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
        if (!threatSearch && _board.wouldMoveCauseCheck(this, x, y))
        {
            _board.setStatus(SELF_CHECK);
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
            else if (_hasMoved == false && _board[x][y] == nullptr && _x + 2 == x && _y == y)
            {
                if (_board[x - 1][y]!=nullptr)
                {
                    _board.setStatus(OCCUPIED_DESTINY);
                    return false; // piece  stands in his way
                }

                if (!threatSearch)
                {
                    _hasMoved = true;
                }
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
            else if (_hasMoved == false && _board[x][y] == nullptr && _x - 2 == x && _y == y)
            {
                if (_board[x + 1][y] != nullptr)
                {
                    _board.setStatus(OCCUPIED_DESTINY);
                    return false; // piece  stands in his way
                }
                if (!threatSearch)
                {
                    _hasMoved = true;
                }
                return true;

            }
        }       
        
        return false;
    
	}






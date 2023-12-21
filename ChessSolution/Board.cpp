#include "Board.h"
 

Board::Board()
	: _turn(true), _currentCheck(false), _chosenPiece(nullptr)
{

	for (int col = A; col < BOARD_DIMENSION; col++)
	{
		_board[1][col] = new Pawn('p',false,1,col,*this); // black pawns line
		_board[6][col] = new Pawn('p', true, 6, col,*this);// white pawns line
	}


}



Piece** Board::operator[](int index)
{
	return  _board[index];
}

string Board::toString() const
{
	string boardString = "";
	for (int row = 0; row < BOARD_DIMENSION; row++)
	{	
		for (int col = A; col < BOARD_DIMENSION; col++)
		{
			if (_board[row][col] != nullptr)
			{
				if (_board[row][col]->getColor() == BLACK)
				{
					boardString += toupper(_board[row][col]->getType()) + " ";
				}
					
				else
				{
					boardString += _board[row][col]->getType() + " ";
				}
			}
			else
			{
				boardString +=   "0 ";
			}
		}
		boardString += "\n";
	}

}


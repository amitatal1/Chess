#include "Board.h"
#define FIRST_ROW 0
#define BLACK_PAWN_PLACEMENT 1
#define WHITE_PAWN_PLACEMENT 6
#define BLACK false
#define WHITE true

Board::Board()
	: _turn(true), _currentCheck(false), _chosenPiece(nullptr)
{

	for (int col = A; col < BOARD_DIMENSION; col++)
	{
		_board[BLACK_PAWN_PLACEMENT][col] = new Pawn('p', BLACK, BLACK_PAWN_PLACEMENT, col,*this); // black pawns line
		_board[WHITE_PAWN_PLACEMENT][col] = new Pawn('p', WHITE, WHITE_PAWN_PLACEMENT, col,*this); // white pawns line
	}


}

Board::~Board()
{
	for(int row = 0; row < BOARD_DIMENSION; row++)
	{
		for (int col = A; col < BOARD_DIMENSION; col++)
		{
			if (_board[row][col] != nullptr)
			{
				delete(_board[row][col]);
			}
			
		}
		
	}
	_kings.clear();
}



Piece** Board::operator[](int index)
{
	return  _board[index];
}

string Board::toString() const
{
	string boardString = "";
	for (int row = FIRST_ROW; row < BOARD_DIMENSION; row++)
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


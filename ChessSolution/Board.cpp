#include "Board.h"

Board::Board()
	: _turn(true), _currentCheck(false), _chosenPiece(nullptr)
{

	for (int col = A; col < BOARD_DIMENSION; col++)
	{
		_board[1][col] = new Pawn();
		_board[6][col] = new Pawn();
	}
}


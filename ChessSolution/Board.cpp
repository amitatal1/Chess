#include "Board.h"
 

Board::Board()
	: _turn(true), _currentCheck(false), _chosenPiece(nullptr)
{

	for (int col = A; col < BOARD_DIMENSION; col++)
	{
		_board[1][col] = new Pawn('p',false,1,col,this); // black pawns line
		_board[6][col] = new Pawn('p', true, 6, col, this);// white pawns line
	}
}

Piece* (*Board::getBoard())[BOARD_DIMENSION][BOARD_DIMENSION]
{
	return &_board;
}


#include "Board.h"
#define BLACK_FIRST_ROW 0
#define WHITE_FIRST_ROW 0

#define BLACK_PAWN_PLACEMENT 1
#define WHITE_PAWN_PLACEMENT 6


Board::Board()
	: _turn(WHITE), _currentCheck(false), _chosenPiece(nullptr)
{

	for (int col = A; col < BOARD_DIMENSION; col++)
	{
		_board[BLACK_PAWN_PLACEMENT][col] = new Pawn(PAWN, BLACK, BLACK_PAWN_PLACEMENT, col,*this); // black pawns line
		_board[WHITE_PAWN_PLACEMENT][col] = new Pawn(PAWN, WHITE, WHITE_PAWN_PLACEMENT, col,*this); // white pawns line
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
	for (int row = BLACK_FIRST_ROW; row < BOARD_DIMENSION; row++)
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

void Board::passTurn()
{
	_turn = !_turn;
}

bool Board::isCheck() const
{
	bool threatColor = !_turn;

	// loop through board
	for (int row = BLACK_FIRST_ROW; row < BOARD_DIMENSION; row++)
	{
		for (int col = A; col < BOARD_DIMENSION; col++)
		{
			if (_board[row][col] != nullptr && _board[row][col]->getColor() == threatColor) // picking up the enemy piexes
			{
				if (_board[row][col]->IsMovePossible(_kings[_turn]->getX(), _kings[_turn]->getY(), true)) // if one  of the enemy's pieces can attack king 
				{
					return true;
				}
			}
		}

	}
	return false;
}

bool Board::wouldMoveCauseCheck(Piece* p, int x, int y)
{
	Piece* replacedSquare = _board[x][y]; // saving the previous square content
	_board[p->getX()][p->getY()]=nullptr;
	_board[x][y] = p;
	bool check = isCheck();

	//returning the original board
	_board[p->getX()][p->getY()] = p;
	_board[x][y] = replacedSquare;
	
	return check;

	
}


#pragma once
#include "Piece.h"
#include "Pawn.h"

#include <string>
#include <vector>

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7

#define PAWN 'p'
#define KNIGHT 'n'
#define QUEEN 'q'
#define ROOK 'r'
#define KING 'k'
#define BISHOP 'b'


# define BOARD_DIMENSION 8 


using std::string;




class Piece;

class Board
{
private:
	Piece* _board[BOARD_DIMENSION][BOARD_DIMENSION];
	bool _turn; // true for white's turn , false for black
	bool _currentCheck;
	Piece* _chosenPiece;
	std::vector<Piece*> _kings;
public:
	Board();
	~Board();
	Piece** operator[](int index); // acting as getter to the function
	string toString() const;
	void passTurn();
	bool isCheck() const;
};


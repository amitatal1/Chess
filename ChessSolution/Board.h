#pragma once
#include "Piece.h"


#include <string>
#include <vector>

#define	LEGAL_MOVE "0"
#define	CHECK "1"
#define	NOT_PLAYER_SOURCE "2"
#define	OCCUPIED_DESTINY "3"
#define	SELF_CHECK "4"
#define	OUT_OF_BORDER "5"
#define	ILLEGAL_MOVE "6"
#define	DESTINY_IS_SOURCE "7"
#define	MATE "8"

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
	string _status;
	std::vector<Piece*> _kings;
public:
	Board();
	~Board();
	Piece* getPiece(int x, int y);
	Piece** operator[](int index); // acting as getter to the function
	string toString() const;
	string getStatus() const;
	void setStatus(const std::string& status);
	bool getTurn() const;
	void passTurn();
	bool isCheck() const;

	bool wouldMoveCauseCheck(Piece* p, int x, int y);

};


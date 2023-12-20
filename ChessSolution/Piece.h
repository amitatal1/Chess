#pragma once
#include "Board.h"

#define BLACK false
#define WHITE true

class Board;

class Piece
{
protected:
	char _type;
	bool _color;
	
	//positions in the board
	int _x;
	int _y;

	Board& _board;
public:
	Piece(char type, bool color, int x, int y, Board& board);
	virtual ~Piece();
	int getX() const;
	int getY() const;

	bool getColor() const;
	char getType() const;
	virtual bool IsMovePossible(int x, int y) =0 ; // checks if certain piece is able to go to move to a specific position 
	virtual bool move(int x, int y) =0 ; // changing the board 



};


#pragma once
#include "Board.h"


class Piece
{
protected:
	char _type;
	bool _color;
	
	//positions in the board
	int _x;
	int _y;

	Board* _board;
public:
	Piece(int x, int y, Board* board, bool color, char type);
	int getX() const;
	int getY() const;

	bool getColor() const;
	char getType() const;
	virtual bool IsMovePossible() =0 ; // checks if certain piece is able to go to move to a specific position 
	virtual bool move(int x, int y) =0 ; // changing the board 
	virtual bool hit(int x, int y)=0; // removing another piece from the board by hitting it



};


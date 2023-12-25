#include "Game.h"
#include <iostream>

using std::cout;
using std::cin;

void Game::Run_Game()
{
	while (true)
	{
		
		cout << _board.toString();
		MakeAjourney();
		_board.passTurn();

	}
}

void Game::MakeAjourney()
{
	
	int piece_row =0 , piece_col=0, dest_row = 0 , dest_col =0 ;
	bool triedOnce = false;
	do
	{
		if (triedOnce) // first time was failure
		{
			cout << "Couldn't made this move... Try again!\n";
		}
		do
		{
			cout << "Enter square that contains your piece:" << std::endl << "Enter col and row in numbers please (1-8): " << std::endl;

			cin >> piece_col >> piece_row;
		}  // while valid choice wasn't made
		while (piece_col < 1 || piece_row < 1 || piece_col > BOARD_DIMENSION || piece_row > BOARD_DIMENSION || _board[piece_row - 1][piece_col - 1] == nullptr || _board[piece_row - 1][piece_col - 1]->getColor() != _board.getTurn());


		do
		{
			cout << "Enter square that you want to move your piece into:" << std::endl << "Enter col and row in numbers please (1-8): " << std::endl;

			cin >> piece_col >> piece_row;
		} while (dest_col < 1 || dest_row < 1 || dest_col > BOARD_DIMENSION || dest_row > BOARD_DIMENSION || _board[dest_row - 1][dest_col - 1] == nullptr || _board[dest_row - 1][dest_col - 1]->getColor() != _board.getTurn());
		triedOnce = true;
	} while (_board[dest_row - 1][dest_col - 1]->move(dest_row, dest_col));

	_log += "(" + std::to_string(piece_col) + ',' + std::to_string(piece_row) + "):(" + std::to_string(dest_col) + "," + std::to_string(dest_row) + ")\n";

}

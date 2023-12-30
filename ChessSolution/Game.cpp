#include "Game.h"
#include <iostream>

using std::cout;
using std::cin;

void Game::Run_Game()
{
	while (true)
	{
		
		std::cout << _board.toString();
		MakeAjourney();
		_board.passTurn();

	}
}

void Game::MakeAjourney() {
    int piece_row, piece_col, dest_row, dest_col;
    bool triedOnce = false;

    do {
        if (triedOnce) {
            std::cout << "Invalid move! Please try again.\n";
        }

        do {
            std::cout << "Enter the coordinates of the piece you want to move (col row): ";
            std::cin >> piece_col >> piece_row;
            Piece* pi = _board[piece_row][piece_col];

        } while (piece_col < 0 || piece_row <0  || piece_col >= BOARD_DIMENSION || piece_row >= BOARD_DIMENSION ||
            _board[piece_row ][piece_col ] == nullptr ||
            _board[piece_row ][piece_col ]->getColor() != _board.getTurn());

        do {
            std::cout << "Enter the destination coordinates (col row): ";
            std::cin >> dest_col >> dest_row;
        } while (dest_col < 0 || dest_row < 0 || dest_col >= BOARD_DIMENSION || dest_row >= BOARD_DIMENSION);

        triedOnce = true;
    } while (!_board[piece_row ][piece_col ]->move(dest_row, dest_col));

    _log += "(" + std::to_string(piece_col) + ',' + std::to_string(piece_row) + "):(" +
        std::to_string(dest_col) + "," + std::to_string(dest_row) + ")\n";
}




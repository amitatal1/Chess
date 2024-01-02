/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Board.h"



using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));


	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	
	Board gameBoard = Board();
	
	char msgToGraphics[1024];
	strcpy_s(msgToGraphics, (gameBoard.toString() + "1").c_str());

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		std::cout << msgFromGraphics << std::endl;
		int srcy = msgFromGraphics[0] - 'a';
		int srcx = msgFromGraphics[1] - '1';
		int dsty = msgFromGraphics[2] - 'a';
		int dstx = msgFromGraphics[3] - '1';
		
		string status = gameBoard.getStatus();
		Piece* squarePiece = gameBoard[srcx][srcy];
		if (!(srcx == dstx && srcy == dsty))
		{
			if (squarePiece != nullptr)
			{
				if (squarePiece->getColor() == gameBoard.getTurn())
				{
					if (squarePiece->move(dstx, dsty))
					{
						gameBoard.passTurn();
						if (gameBoard.isCheck())
						{
							status = CHECK;
						}
						else
						{
							status = LEGAL_MOVE;
						}
						strcpy_s(msgToGraphics, status.c_str());
					}
					else
					{
						strcpy_s(msgToGraphics, gameBoard.getStatus().c_str());
					}
				}
				else
				{
					status = OCCUPIED_DESTINY;
					strcpy_s(msgToGraphics, status.c_str());
				}
			}
			else
			{
				status = NOT_PLAYER_SOURCE;
				strcpy_s(msgToGraphics, status.c_str());
			}
		}
		else
		{
			status = DESTINY_IS_SOURCE;
			strcpy_s(msgToGraphics, status.c_str());
		}
		


//		/******* JUST FOR EREZ DEBUGGING ******/
//		int r = rand() % 10; // just for debugging......
//		msgToGraphics[0] = (char)(1 + '0');
//		msgToGraphics[1] = 0;
//		/******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}
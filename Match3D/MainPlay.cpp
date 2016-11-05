/* 	C++ implementation of a 3D Tic-Tac-Toe game. This class will facilitate all 
*	player interaction with the game board, display the current game board, 
*	track current scores, display a victory screen and handle multiple play sessions.

*	Alex vanKooten
*	St#4789665
*	Updated Nov.5.2016	*/

#include <iostream>
#include "Board.h"

char mainMenu(Board board) {
	char select = 'Y'; //character o hold player selections temporarily

	std::cout << "Welcome to Match 3D! A virtual game of 3-Dimensional Tic-Tac-Toe! \n";
	std::cout << "To start, would you like to be X's (First Move) or O's (Second Move)? \n";
	std::cout << "Please enter X or O here: ";
	while (select != 'O' && select != 'X') {
		while (!(std::cin >> select)){ //make sure a char is received
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "That's not valid selection! Please try again.\n";
	}
	std::cout << "Great choice! Now I'll explain a little bit about the game.\n";
	std::cout << "Let's look at the game board. There are 8 towers (labelled A to H)\n";

	board.showBoard();
	system("PAUSE");
	std::cout << "Each turn you'll place your piece (X or O) onto one of the towers.\n";
	
	return select;
}

int main() {
	Board board;	//it's hard to play a game without a board
	bool xTurn;		//this will determine whose turn it is (True = X's turn)
	xTurn = mainMenu(board);	//explain the game and prompt player for shape choice 	
	
	char select;
	for (;;) {

		std::cout << "Which tower would you like to put your piece onto? \n";

		while (!(std::cin >> select)){ //make sure a char is received
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "That's not valid selection! Please try again.\n";
		}
		switch (select) {
			case 'A': case 'a': case '1': //place piece in Column A
				board.makeMove(xTurn, 1);
				break;
			case 'B': case 'b': case '2': //place piece in Column B

				break;
			case 'C': case 'c': case '3': //place piece in Column C

				break;
			case 'D': case 'd': case '4': //place piece in Column D

				break;
			case 'E': case 'e': case '5': //place piece in Column E

				break;
			case 'F': case 'f': case '6': //place piece in Column F

				break;
			case 'G': case 'g': case '7': //place piece in Column G

				break;
			case 'H': case 'h': case '8': //place piece in Column H

				break;
			case 'Q': case 'q':	//quit test harness
				return 0;
				break;
			default: //Optional
				std::cout << "That's not one of the selections!\n";
		}
	}

	system("PAUSE");
	return 0;
}
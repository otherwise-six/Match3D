/* 	C++ implementation of a 3D Tic-Tac-Toe game. This class will facilitate all 
*	player interaction with the game board, display the current game board, 
*	track current scores, display a victory screen and handle multiple play sessions.

*	Alex vanKooten
*	St#4789665
*	Updated Nov.5.2016	*/

#include <iostream>
#include "Board.h"

void mainMenu() {
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

	//showBoard();
	system("PAUSE");
	std::cout << "Each turn you'll place your piece (X or O) onto one of the towers.\n";

}

int main() {
	//Board board;	//it's hard to play a game without a board
	mainMenu();
	
	char select;
	for (;;) {

		std::cout << "Which tower would you like to put your piece onto? \n";

		while (!(std::cin >> select)){ //make sure an char is received
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "That's not valid selection! Please try again.\n";
		}
		switch (select) {
		case '1': //place piece in Column A

			break;
		case 'A': //place piece in Column A
			
			break;
		case 'a': //place piece in Column A
			
			break;
		case '2': //place piece in Column B

			break;
		case 'B': //place piece in Column B

			break;
		case 'b': //place piece in Column B

			break;
		case '3': //place piece in Column C

			break;
		case 'C': //place piece in Column C

			break;
		case 'c': //place piece in Column C

			break;
		case '4': //place piece in Column D

			break;
		case 'D': //place piece in Column D

			break;
		case 'd': //place piece in Column D

			break;
		case '5': //place piece in Column E

			break;
		case 'E': //place piece in Column E

			break;
		case 'e': //place piece in Column E

			break;
		case '6': //place piece in Column F

			break;
		case 'F': //place piece in Column F

			break;
		case 'f': //place piece in Column F

			break;
		case '7': //place piece in Column G

			break;
		case 'G': //place piece in Column G

			break;
		case 'g': //place piece in Column G

			break;
		case '8': //place piece in Column H

			break;
		case 'H': //place piece in Column H

			break;
		case 'h': //place piece in Column h

			break;
		case 'Q':	//quit test harness
			
			return 0;
			break;
		case 'q':	//quit test harness
			
			return 0;
			break;
		default: //Optional
			std::cout << "That's not one of the selections!\n";
		}
	}

	system("PAUSE");
	return 0;
}
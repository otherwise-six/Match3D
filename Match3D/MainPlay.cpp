/* 	C++ implementation of a 3D Tic-Tac-Toe game. This class will facilitate all 
*	player interaction with the game board, display the current game board, 
*	track current scores, display a victory screen and handle multiple play sessions.

*	Alex vanKooten
*	St#4789665
*	Updated Nov.5.2016	*/

#include <iostream>
#include <windows.h>
#include "Board.h"
#undef max

/*Ask the player a yes or no question*/
bool yes() {
	char select = 'Z';
	/*Players choose either Y or N*/
	while (select != 'Y' && select != 'N') {
		while (!(std::cin >> select)){ //make sure a char is received
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
		if (select != 'Y' && select != 'N') {
			std::cout << "That's not a valid selection! Please choose Y or N.\n";
		}
	}
	if (select == 'Y') {
		return true;
	}
	return false;
}

char mainMenu(Board board) {
	char select = 'Z'; //holds player selections temporarily
	char piece = 'X';  //players selected gaming piece
	bool xTurn;		//just determines which "player" is "making moves" for tutorial

	std::cout << "Welcome to Match 3D! A virtual game of 3-Dimensional Tic-Tac-Toe! \n";
	std::cout << "To start, would you like to be X's (First Move) or O's (Second Move)? \n";
	std::cout << "Please enter X or O here: ";
	
	/*Players must select either X's or O's as their game piece*/
	while (select != 'O' && select != 'X') {
		while (!(std::cin >> select)){ //make sure a char is received
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (select != 'O' && select != 'X') {
			std::cout << "That's not a valid selection! Please choose either X or O.\n";
		}
	}
	piece = select;	//set player's piece to their selection
	if (select == 'X') {
		xTurn = true;	//player chose X's
	} else {
		xTurn = false;	//player chose O's
	}

	std::cout << "\nGreat choice! Would you like to see the full tutorial?\n";
	std::cout << "Please select yes (Y) or no (N):";

	/*Players can choose to see the full tutorial or jump right into the game*/
	if (yes()) { //Give the Player a full game explanation
		std::cout << "\nWelcome to the in-depth tutorial!\n";
		std::cout << "Let's look at the game board. There are 8 towers (labelled A to H)\n";

		board.printBoard(piece);
		system("PAUSE");

		std::cout << "\nEach turn you'll place your piece (X or O) onto one of the towers (A to H).\n";
		std::cout << "On your turn, you can place your piece by either pressing the tower letter\n";
		std::cout << "or the associated tower number. (Ex. A or 1 will place a piece on Tower A)\n";
		std::cout << "Try placing a piece on tower F for practice (You can press F or 5)\n";

		/*Making sure players understand how to place a piece*/
		while (select != 'F' && select != '5') {
			while (!(std::cin >> select)){ //make sure a char is received
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (select != 'F' && select != '5'){
				std::cout << "Humour me! Just try pressing F or 5.\n";
			}
		}
		board.makeMove(xTurn, 5);
		board.printBoard(piece);
		std::cout << "Good job! Do you see your piece on the board now? \n";
		system("PAUSE");
		std::cout << "\nNotice that your piece was placed at the bottom of the tower.\n";
		std::cout << "That's right! Gravity exists here too! You can't place a piece on a higher\n";
		std::cout << "level until either you (or your opponent) have a piece below it!\n";
		system("PAUSE");
		std::cout << "\nThe main goal of the game is to get AS MANY connections of 3 as you can!\n";
		std::cout << "Unlike regular tic-tac-toe this game doesn't end when one person matches 3.\n";
		std::cout << "Instead, you get one point for every connection of 3 pieces you make.\n";
		std::cout << "You and your opponent take turns placing pieces until every tower is full.\n";
		std::cout << "And whichever player has the most points at the end is the GRAND VICTOR!\n";
		std::cout << "Last thing before you get started, I'll show you what counts as a point:\n";
		system("PAUSE");

		/*hard coding in examples of points. This one is a full column*/
		board.clearBoard();
		board.hardMove(xTurn, 0, 0);
		board.hardMove(xTurn, 0, 1);
		board.hardMove(xTurn, 0, 2);
		board.printBoard(piece);
		std::cout << "Control a whole tower like this? That a point!\n";
		system("PAUSE");

		/*full row*/
		board.clearBoard();
		board.hardMove(xTurn, 0, 0);
		board.hardMove(xTurn, 1, 0);
		board.hardMove(xTurn, 2, 0);
		board.hardMove(xTurn, 5, 1);
		board.hardMove(xTurn, 6, 1);
		board.hardMove(xTurn, 7, 1);
		board.printBoard(piece);
		std::cout << "Have 3 pieces in a row on the same levels of adjacent towers? POINTS!\n";
		system("PAUSE");

		/*diagonal row*/
		board.clearBoard();
		board.hardMove(xTurn, 0, 0);
		board.hardMove(xTurn, 3, 0);
		board.hardMove(xTurn, 6, 0);
		board.hardMove(xTurn, 1, 2);
		board.hardMove(xTurn, 4, 2);
		board.hardMove(xTurn, 7, 2);
		board.printBoard(piece);
		std::cout << "Note that these are also a points! Diagonally adjacent towers count too!\n";
		system("PAUSE");

		/*multi-platform diagonal*/
		board.clearBoard();
		board.hardMove(xTurn, 0, 0);
		board.hardMove(xTurn, 3, 1);
		board.hardMove(xTurn, 6, 2);
		board.hardMove(xTurn, 1, 1);
		board.hardMove(xTurn, 2, 2);
		board.printBoard(piece);
		std::cout << "Here's where it gets a bit tricky, you also get points for connecting pieces\n"; 
		std::cout << "diagonally up or down adjacent towers! This would be 2 points for you!\n";
		system("PAUSE");
		std::cout << "\nI think that pretty much covers it. Try to get as many connecting groups\n";
		std::cout << "of 3 as you can while blocking your opponent from doing the same!\n";
		std::cout << "And most importantly, have some fun!!!\n";
		board.clearBoard();
	}
	std::cout << "\nAlright! Let's get started!\n";
	return piece;	//return the selected player piece and start playing!
}

/*evaluate a specified row within the 3D space of the board*/
void evalRow(Board &b, int row, int x, int y, int z, char testPiece, int value) {
	if (b.getPiece(x, row) == '\0' && b.getPiece(y, row) == testPiece && b.getPiece(z, row) == testPiece) {
		b.setWeight(x, row, value);
	}
	else if (b.getPiece(y, row) == '\0' && b.getPiece(x, row) == testPiece && b.getPiece(z, row) == testPiece) {
		b.setWeight(y, row, value);
	}
	else if (b.getPiece(z, row) == '\0' && b.getPiece(x, row) == testPiece && b.getPiece(y, row) == testPiece) {
		b.setWeight(z, row, value);
	}
}

/*evaluate a specified row within the 3D space of the board*/
void evalDiag(Board &b, int x1, int x2, int y1, int y2, char testPiece, int value) {
	if (b.getPiece(x1, x2) == '\0' && b.getPiece(y1, y2) == testPiece) {
		b.setWeight(x1, x2, value);
	}
	if (b.getPiece(y1, y2) == '\0' && b.getPiece(x1, x2) == testPiece) {
		b.setWeight(y1, y2, value);
	}
}

/*The computer player will determine and make the move it thinks is best*/
void computerMove(Board &b, char piece, char enemy) {
	int weight = 20;	//high priority weight for blocking
	char checkPiece = enemy;	//acts as a switch for blocking and seeking points

	/*first check for blockable, then check for points*/
	for (int n = 0; n < 2; n++) {
		if (n = 1) {
			checkPiece = piece;
			weight = 10;	//second highest priority for matching
		}
		/*go through towers*/
		for (int i = 0; i < 8; i++) {
			/*check for nearly complete columns*/
			if (b.getPiece(i, 0) == checkPiece && b.getPiece(i, 1) == checkPiece) {
				b.setWeight(i, 2, weight);
			}
		}

		/*go through and check for nearly complete rows*/
		for (int j = 0; j < 3; j++) {
			evalRow(b, j, 0, 1, 2, checkPiece, weight); //evaluate "back" rows
			evalRow(b, j, 5, 6, 7, checkPiece, weight); //evaluate "front" rows
			evalRow(b, j, 0, 3, 6, checkPiece, weight); //evaluate "left \" rows
			evalRow(b, j, 1, 3, 5, checkPiece, weight); //evaluate "left /" rows
			evalRow(b, j, 1, 4, 7, checkPiece, weight); //evaluate "right \" rows
			evalRow(b, j, 2, 4, 6, checkPiece, weight); //evaluate "right /" rows	
		}

		/*check for nearly complete diagonals through D*/
		if (b.getPiece(3, 1) == checkPiece) {
			evalDiag(b, 0, 0, 6, 2, checkPiece, weight);
			evalDiag(b, 6, 0, 0, 2, checkPiece, weight);
			evalDiag(b, 5, 0, 1, 2, checkPiece, weight);
			evalDiag(b, 1, 0, 5, 2, checkPiece, weight);
		}
		/*check for nearly complete diagonals through E*/
		if (b.getPiece(4, 1) == checkPiece) {
			evalDiag(b, 1, 0, 7, 2, checkPiece, weight);
			evalDiag(b, 7, 0, 1, 2, checkPiece, weight);
			evalDiag(b, 2, 0, 6, 2, checkPiece, weight);
			evalDiag(b, 6, 0, 2, 2, checkPiece, weight);
		}

		/*check for nearly completediagonals through B*/
		if (b.getPiece(1, 1) == checkPiece) {
			evalDiag(b, 0, 0, 2, 2, checkPiece, weight);
			evalDiag(b, 2, 0, 0, 2, checkPiece, weight);
		}

		/*check for nearly complete diagonals through G*/
		if (b.getPiece(6, 1) == checkPiece) {
			evalDiag(b, 5, 0, 7, 2, checkPiece, weight);
			evalDiag(b, 7, 0, 5, 2, checkPiece, weight);
		}
	}
	/*
			int j = b.getTowerHeight(i);
			if (j = 1) { //we could fill this tower
				//if (b.)
			}
			temp = b.getWeight(i, j);
			//if (j < 2) { //account for how valuable the space above this move would be
			//	temp = temp - (b.weightArray[i][j + 1] / 2);
			//}
        }
	}*/
}

/*Tally the final scores and declare a winner*/
void declareWinner(Board &b, char player, char com) {
	int playerScore = b.calcScore(player);
	int comScore = b.calcScore(com);
	std::cout << "\nTallying Final Scores...\n";
	if (playerScore == comScore) {
		std::cout << "\nIT'S A TIE!!! You put up a really great fight!\n\n";
	}
	else if (playerScore > comScore) {
		std::cout << "\nYOU WIN!!! It looks like I was no match for " << player << "'s this time!\n\n";
	}
	else if (playerScore < comScore) {
		std::cout << "\nYOU LOSE!!! Better luck next time player! Maybe " << com << "'s are lucky for me?\n\n";
	}
}

int main() {
	Board board;		//it's hard to play a game without a board
	bool xTurn = true;	//this will determine whose turn it is (X always starts)
	bool moved;         //will determine if a successful move has occured
	char playerPiece, comPiece;	    //hold's the player's and computer's selected playing pieces
	playerPiece = mainMenu(board);	//prompt player for piece choice and explain game (if requested)
	char select;		//temporarily hold move selections
	
	if (playerPiece == 'O') {
		comPiece = 'X';
        //COMPUTER MOVES
		computerMove(board, comPiece, playerPiece);
		xTurn = !xTurn;
	} else {
		comPiece = 'O';
	}
	/*Loop forever until the player exits~*/
	for (;;){
		while (!board.boardFull()) {
			moved = false;  //reset the flag (player hasn't moved until valid selection made
			board.printBoard(playerPiece);
			std::cout << "\nSelect a tower to place your piece on: ";

			while (!(std::cin >> select)){ //make sure a char is received
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "That's not valid selection! Please try again.\n";
			}
			switch (select) {
			case 'A': case 'a': case '1': //place piece in Column A
				if (!board.towerFull(0)) {  //test for space in tower
					board.makeMove(xTurn, 0);   //make move
					moved = true;   //set the player's moved flag to true
				} else {
					std::cout << "\nTower A is already full!!!\n";
				}
				break;
			case 'B': case 'b': case '2': //place piece in Column B
				if (!board.towerFull(1)) {
					board.makeMove(xTurn, 1);
					moved = true;
				} else {
					std::cout << "\nTower B is already full!!!\n";
				}
				break;
			case 'C': case 'c': case '3': //place piece in Column C
				if (!board.towerFull(2)) {
					board.makeMove(xTurn, 2);
					moved = true;
				} else {
					std::cout << "\nTower C is already full!!!\n";
				}
				break;
			case 'D': case 'd': case '4': //place piece in Column D
				if (!board.towerFull(3)) {
					board.makeMove(xTurn, 3);
					moved = true;
				} else {
					std::cout << "\nTower D is already full!!!\n";
				}
				break;
			case 'E': case 'e': case '5': //place piece in Column E
				if (!board.towerFull(4)) {
					board.makeMove(xTurn, 4);
					moved = true;
				} else {
					std::cout << "\nTower E is already full!!!\n";
				}
				break;
			case 'F': case 'f': case '6': //place piece in Column F
				if (!board.towerFull(5)) {
					board.makeMove(xTurn, 5);
					moved = true;
				} else {
					std::cout << "\nTower F is already full!!!\n";
				}
				break;
			case 'G': case 'g': case '7': //place piece in Column G
				if (!board.towerFull(6)) {
					board.makeMove(xTurn, 6);
					moved = true;
				} else {
					std::cout << "\nTower G is already full!!!\n";
				}
				break;
			case 'H': case 'h': case '8': //place piece in Column H
				if (!board.towerFull(7)) {
					board.makeMove(xTurn, 7);
					moved = true;
				} else {
					std::cout << "\nTower H is already full!!!\n";
				}
				break;
			case 'Q': case 'q':	//Quit (and hopefully don't break the world)
				std::cout << "\nThank you for playing! The program will now close.\n";
				system("PAUSE");
				return 0;
				break;
			default: //Optional
				std::cout << "That's not one of the selections!\n";
			}
			if (moved) { //computer makes their move after player has successfully played a piece
				//COMPUTER MOVES (For now expressed as me changing the turn)
				xTurn = !xTurn;
			}
		}
		board.printBoard(playerPiece);
		declareWinner(board, playerPiece, comPiece);
		/*Ask for rematch*/
		std::cout << "Would you like to play another match? (Y or N):";
		if (yes()) {
			/*If they're playing again, do they want to keep the same pieces?*/
			std::cout << "Would you like to swap your pieces for the computers? (Y or N):";
			if (yes()) {
				/*Swap the player and computer pieces*/
				if (playerPiece == 'O') {
					playerPiece = 'X';
					comPiece = 'O';
				} else {
					playerPiece = 'O';
                    comPiece = 'X';
				}
			}
			board.clearBoard();
		} else {  //The player doesn;t want a rematch. Exit.
			std::cout << "\nThank you for playing! The program will now close.\n";
			system("PAUSE");
			return 0;
		}
	}
	board.~Board();
	system("PAUSE");
	return 0;
}
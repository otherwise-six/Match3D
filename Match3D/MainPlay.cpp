/* 	C++ implementation of a 3D Tic-Tac-Toe game. This class will facilitate all 
*	player interaction with the game board, display the current game board, 
*	track current scores, display a victory screen and handle multiple play sessions.
*
*	Alex vanKooten
*	St#4789665
*	Updated Nov.11.2016	*/

#include <iostream>
#include "Board.h"
#include "MatchMaker.h"
#undef max

/*Ask the player a yes or no question*/
bool yes() {
	char select = 'Z';
	/*Players choose either Y or N*/
	while (select != 'Y' && select != 'N' && select != 'y' && select != 'n') {
		while (!(std::cin >> select)){ //make sure a char is received
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
		if (select != 'Y' && select != 'N' && select != 'y' && select != 'n') {
			std::cout << "That's not a valid selection! Please choose Y or N.\n";
		}
	}
	if (select == 'Y' || select == 'y') {
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
	std::cout << "Please enter a capital X or O here: ";
	
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
		std::cout << "or the associated tower number. (Ex. A or 5 will place a piece on Tower A)\n";
		std::cout << "Try placing a piece on tower F for practice (You can press F or 1)\n";

		/*Making sure players understand how to place a piece*/
		while (select != 'F' && select != 'f' && select != '1') {
			while (!(std::cin >> select)){ //make sure a char is received
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (select != 'F' && select != 'f' && select != '1'){
				std::cout << "Humour me! Just try pressing F or 1!\n";
			}
		}
		board.makeMove(xTurn, 1);
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

/*Tally the final scores and declare a winner*/
void declareWinner(Board &b, char player, char com) {
	int playerScore = b.calcScore(player);
	int comScore = b.calcScore(com);
	std::cout << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	std::cout << "||                                                                       ||\n";
	std::cout << "|| Tallying Final Scores...                                              ||\n";
	if (playerScore == comScore) {
		std::cout << "|| IT'S A TIE!!! You put up a really great fight!                        ||\n";
	}
	else if (playerScore > comScore) {
		std::cout << "|| YOU WIN!!! It looks like I was no match for " << player << "'s this time!            ||\n";
	}
	else if (playerScore < comScore) {
		std::cout << "|| YOU LOSE!!! Better luck next time player! Maybe " << com << "'s are lucky for me? ||\n";
	}
	std::cout << "||                                                                       ||\n";
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n";
	system("PAUSE");
}

int main() {
	Board board;		//it's hard to play a game without a board
	MatchMaker greedy;  //this guy will take care of making moves
	bool xTurn = true;	//this will determine whose turn it is (X always starts)
	bool moved;         //will determine if a successful move has occured
	char playerPiece, comPiece;	    //hold's the player's and computer's selected playing pieces
	playerPiece = mainMenu(board);	//prompt player for piece choice and explain game (if requested)
	char select;		//temporarily hold move selections
	int comMove;		//the tower that the computer has decided to place a piece on

	if (playerPiece == 'O') { //then computer will make first move
		comPiece = 'X';
		/*computer moves first if player has selected to be O's*/
		comMove = greedy.computerMove(board, comPiece, playerPiece);
		board.makeMove(xTurn, comMove);
		xTurn = !xTurn;
	} else {
		comPiece = 'O';
	}

	/*Loop forever until the player exits~*/
	for (;;) {
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
			case 'F': case 'f': case '1': //place piece in Column F
				if (!board.towerFull(0)) {
					board.makeMove(xTurn, 0);
					moved = true;
				}
				break;
			case 'G': case 'g': case '2': //place piece in Column G
				if (!board.towerFull(1)) {
					board.makeMove(xTurn, 1);
					moved = true;
				}
				break;
			case 'H': case 'h': case '3': //place piece in Column H
				if (!board.towerFull(2)) {
					board.makeMove(xTurn, 2);
					moved = true;
				}
				break;
			case 'D': case 'd': case '4': //place piece in Column D
				if (!board.towerFull(3)) {
					board.makeMove(xTurn, 3);
					moved = true;
				}
				break;
			case 'E': case 'e': case '5': //place piece in Column E
				if (!board.towerFull(4)) {
					board.makeMove(xTurn, 4);
					moved = true;
				}
				break;
			case 'A': case 'a': case '6': //place piece in Column A
				if (!board.towerFull(5)) {  //test for space in tower
					board.makeMove(xTurn, 5);   //make move
					moved = true;   //set the player's moved flag to true
				}
				break;
			case 'B': case 'b': case '7': //place piece in Column B
				if (!board.towerFull(6)) {
					board.makeMove(xTurn, 6);
					moved = true;
				}
				break;
			case 'C': case 'c': case '8': //place piece in Column C
				if (!board.towerFull(7)) {
					board.makeMove(xTurn, 7);
					moved = true;
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
			if (moved) { //computer waits until player has successfully played a piece
				/*changes the turn, computer plays, then returns to player turn*/
				xTurn = !xTurn;
				comMove = greedy.computerMove(board, comPiece, playerPiece);
				board.makeMove(xTurn, comMove);
				xTurn = !xTurn;
			}
		}
		board.printBoard(playerPiece);
		declareWinner(board, playerPiece, comPiece);
		/*Ask for rematch*/
		std::cout << "Would you like to play another match? (Y or N): ";
		if (yes()) {
			/*If they're playing again, do they want to keep the same pieces?*/
			std::cout << "Would you like to swap your pieces for the computers? (Y or N): ";
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
			xTurn = true;	//X's always go first!
			if (playerPiece == 'O') { //if player is O's after choices, computer will make first move
				comMove = greedy.computerMove(board, comPiece, playerPiece);
				board.makeMove(xTurn, comMove);
				xTurn = !xTurn;
			}
		} else {  //The player doesn't want a rematch, exit.
			std::cout << "\nThank you for playing! The program will now close.\n";
			system("PAUSE");
			return 0;
		}
	}
	board.~Board();
	greedy.~MatchMaker();
	system("PAUSE");
	return 0;
}; //Match3D
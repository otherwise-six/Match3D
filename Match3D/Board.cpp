/* 	This class will store information representing all factors for a 3D Tic-Tac-Toe game. 
*	The board has 8 pegs (A through H) each with 3 spaces for players to place pieces.
*	The 8 pegs are arranged in two rows of 3 with a row of 2 between them.
*	Players can only place pieces on pegs from the bottom upwards.
*	All board states and statistics will be accessible via this class.

*	Alex vanKooten
*	St#4789665
*	Updated Nov.5.2016	*/

#include <iostream>
#include "Board.h"

/*The initial weights I assign to every position on the board based on percieved value*/
const int Board::initWeightArray[8][3] = {
	{ 4, 3, 4 }, { 6, 6, 6 }, { 4, 3, 4 },
	      { 3, 5, 3 }, { 3, 5, 3 }, 
	{ 4, 3, 4 }, { 6, 6, 6 }, { 4, 3, 4 } };

/*basic board constructor*/
Board::Board() {
	clearBoard();
}

/*basic destructor*/
Board::~Board() {
}

/*reset all board parameters to default*/
void Board::clearBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			weightArray[i][j] = initWeightArray[i][j];
			boardArray[i][j] = '\0';	//empty space
		}
	}
}

/*show the current state of the board in ASCII*/
void showBoard() {
	std::cout << "\n";
}
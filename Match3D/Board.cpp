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
	{ 4, 3, 4 }, { 6, 6, 6 }, { 4, 3, 4 } 
};

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
			weightArray[i][j] = initWeightArray[i][j];	//reset board weights
			boardArray[i][j] = '\0';	//set board spaces to empty space
		}
		towerHeight[i] = 0;	//"tear down" the towers
	}
}

/*returns true if the selected tower is already full*/
bool Board::towerFull(int tower) {
	if (towerHeight[tower] >= 3) { //check for full tower
		std::cout << "This tower is already full!\n";
		return true;
	}
	return false;
}

/*calculate the score of a given player on the current board*/
int Board::calcScore(char player) {
	//MATHS
	return 0;
}

/*add a piece ignoring gravity(for examples only)*/
void Board::hardMove(bool xTurn, int tower, int height) {
	if (tower < 8 && height < 3) {	//valid move
		if (xTurn) { //add an X to selected tower
			boardArray[tower][height] = 'X';	
		} else { //add an O to selected tower
			boardArray[tower][height] = 'O';
		}
	} else {
		std::cout << "That's not a valid move you dummy! How do you hard code a move wrong!?";
	}
}

/*add a players move to the board*/
void Board::makeMove(bool xTurn, int tower) {
	if (towerHeight[tower] >= 3) { //check for full tower
		std::cout << "This tower is already full!\n";
	} else {	//tower is still a valid selection
		if (xTurn) { //add an X to selected tower
			boardArray[tower][towerHeight[tower]] = 'X';
		}
		else {	 //add an O to selected tower
			boardArray[tower][towerHeight[tower]] = 'O';
		}
		towerHeight[tower]++;	//increment the tower height
	}
}

/*show the current state of the board in ASCII*/
void Board::printBoard(char piece) {
	char antiPiece = 'X';
	if (piece == 'X') {
		antiPiece = 'O';
	}

	std::cout << "\n   A     B     C";
	std::cout << "\n  [" << boardArray[0][2] << "]   [" << boardArray[1][2] << "]   [" << boardArray[2][2] << "]";
	std::cout << "\n  [" << boardArray[0][1] << "]   [" << boardArray[1][1] << "]   [" << boardArray[2][1] << "]";
	std::cout << "\n  [" << boardArray[0][0] << "]   [" << boardArray[1][0] << "]   [" << boardArray[2][0] << "]";
	std::cout << "\n      D     E";
	std::cout << "\n     [" << boardArray[3][2] << "]   [" << boardArray[4][2] << "]";
	std::cout << "       Player (" << piece << ") Score: " << calcScore(piece);
	std::cout << "\n     [" << boardArray[3][1] << "]   [" << boardArray[4][1] << "]";
	std::cout << "\n     [" << boardArray[3][0] << "]   [" << boardArray[4][0] << "]";
	std::cout << "       Computer (" << antiPiece << ") Score: " << calcScore(antiPiece);
	std::cout << "\n   F     G     H";
	std::cout << "\n  [" << boardArray[5][2] << "]   [" << boardArray[6][2] << "]   [" << boardArray[7][2] << "]";
	std::cout << "\n  [" << boardArray[5][1] << "]   [" << boardArray[6][1] << "]   [" << boardArray[7][1] << "]";
	std::cout << "\n  [" << boardArray[5][0] << "]   [" << boardArray[6][0] << "]   [" << boardArray[7][0] << "]\n\n";
}
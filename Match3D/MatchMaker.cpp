/* 	This classg to a  will take in information sent to it by the main class and run some basic
*   calculations on the state of the board. Given the board state the greedy algorithm will 
*   determine, state and then return it's optimal move.
*
*	Alex vanKooten
*	St#4789665
*	Updated Nov.11.2016	*/

#include "Board.h"
#include "MatchMaker.h"
#include <iostream>

/*default constructor*/
MatchMaker::MatchMaker() {
	//We don't actually store anything permanently so this is blank~
}

/*default destructor*/
MatchMaker::~MatchMaker() {
	//Destruction stuff
}

/*evaluate a specified row within the 3D space of the board*/
void MatchMaker::evalRow(Board &b, int row, int x, int y, int z, char testPiece, int value) {
	if (b.getPiece(x, row) == '\0' && b.getPiece(y, row) == testPiece && b.getPiece(z, row) == testPiece) {
		b.addWeight(x, row, value);
	}
	else if (b.getPiece(y, row) == '\0' && b.getPiece(x, row) == testPiece && b.getPiece(z, row) == testPiece) {
		b.addWeight(y, row, value);
	}
	else if (b.getPiece(z, row) == '\0' && b.getPiece(x, row) == testPiece && b.getPiece(y, row) == testPiece) {
		b.addWeight(z, row, value);
	}
}

/*evaluate a specified row within the 3D space of the board*/
void MatchMaker::evalDiag(Board &b, int x1, int x2, int y1, int y2, char testPiece, int value) {
	if (b.getPiece(x1, x2) == '\0' && b.getPiece(y1, y2) == testPiece) {
		b.addWeight(x1, x2, value);
	}
	if (b.getPiece(y1, y2) == '\0' && b.getPiece(x1, x2) == testPiece) {
		b.addWeight(y1, y2, value);
	}
}

/*The computer player will determine and make the move it thinks is best*/
int MatchMaker::computerMove(Board &b, char piece, char enemy) {
	int weight = 40;	//high priority weight for blocking
	char checkPiece = enemy;	//acts as a switch for blocking and seeking points
	int bestMove = 0;			//the best move for the computer (value to be returned)
	int bestScore = 0;			//the perceived score of the best move

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
				b.addWeight(i, 2, weight);
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

	/*Now that the weights have been updated for the current board state
	* run through the possible moves one more time (evaluating for
	* ramifications) and store the best move for return.*/
	for (int z = 0; z < 8; z++) {
		int height = b.getTowerHeight(z);
		if (height < 3) { //this is still a valid tower to move to
					
						  //Depricated logic. Proved unneccessary and occasionally detrimental to play.	 
						  /*if (height < 2) { //the player will be able to move above you
						  int temp = b.getWeight(z, height);
						  //If above pos is valuable, the move is less appealing as player can steal
						  b.setWeight(z, height, temp - (b.getWeight(z, height + 1) / 3));
						  }*/
			
			/*uncomment below for weight checking*/
			//std::cout << "Tower[" << z << ", " << height << "] weight= " << b.getWeight(z, height) << "\n";
			
			/*check for the best scoring move*/
			if (bestScore < b.getWeight(z, height)) {
				bestScore = b.getWeight(z, height);
				bestMove = z;
				//std::cout << "bestMove= " << z << "\n";
			}
		}
	}
	std::cout << "\nYour Opponent has placed a piece on Tower " << b.getTowerName(bestMove) << "\n";
	return bestMove;	//DO THE THING!
};
/* 	This class will store information representing all factors for a 3D Tic-Tac-Toe game.
*	The board has 8 pegs (A through H) each with 3 spaces for players to place pieces.
*	The 8 pegs are arranged in two rows of 3 with a row of 2 between them.
*	Players can only place pieces on pegs from the bottom upwards.
*	All board states and statistics will be accessible via this class.

*	Alex vanKooten
*	St#4789665
*	Updated Nov.5.2016	*/

#pragma once

class Board {
public:
	Board();	//Basic board constructor
	~Board();
	void clearBoard();		//reset all board parameters to default
	void printBoard(char);	//show the current state of the board in ASCII
	int calcScore(char);	//calculate the score of a given player on the current board
	bool towerFull(int); //returns true if the selected tower is already full
	void makeMove(bool, int);	//add a players move to the board
	void hardMove(bool, int, int);	//add a piece ignoring gravity (for examples only)
private:
	static const int initWeightArray[8][3];	//initial board weights
	int	weightArray[8][3];	//updated weights on every space for greedy heuristic
	char boardArray[8][3];	//saves which pieces are on the current board
	int towerHeight[8];		//stores how many pieces are in each tower already
};


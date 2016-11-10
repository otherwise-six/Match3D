/* 	This header defines all information representing the factors of a 3D Tic-Tac-Toe game.
*	The board has 8 pegs (A through H) each with 3 spaces for players to place pieces.
*	The 8 pegs are arranged in two rows of 3 with a row of 2 between them.
*	Players can only place pieces on pegs from the bottom upwards.
*   All board states and statistics will be defined in this header.
*
*	Alex vanKooten
*	St#4789665
*	Updated Nov.11.2016	*/

#pragma once

class Board {
public:
	Board();	//Basic board constructor
	~Board();
	void clearBoard();		//reset all board parameters to default
	void printBoard(char);	//show the current state of the board in ASCII
	void makeMove(bool xTurn, int tower);	//add a players move to the board
	void hardMove(bool xTurn, int tower, int height);	//add a piece ignoring gravity (for examples only)
	void setWeight(int tower, int height, int value);	//sets the weight of the selected board space to the given value
	void addWeight(int tower, int height, int value);	//adds weight to the selected board space
	bool towerFull(int tower);  //returns true if the selected tower is already full
	bool boardFull();			//returns true if the board is full (used to determine game over)
	int getTowerHeight(int);	//return the height of specified Tower
	char getTowerName(int);		//returns the character name for the tower given it's number	
	int getWeight(int tower, int height);	//return the weight of the selected board space
	int calcScore(char playerPiece);		//calculate the score of a given player on the current board
	char getPiece(int tower, int height);	//returns the piece occupying the given board space
private:
	static const int initWeightArray[8][3];	//initial board weights
	static const char towerName[8];			//holds the character name of each tower
	char boardArray[8][3];	//saves which pieces are on the current board
	int	weightArray[8][3];	//updated weights on every space for greedy heuristic
	int towerHeight[8];		//stores how many pieces are in each tower already
};


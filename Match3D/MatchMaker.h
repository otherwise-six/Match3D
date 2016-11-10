/* 	This header defines all information pertaining to a gameplaying thread "Matchmaker".
*   This will be fed game info by the main program and calculate the best move possible. 
*   All evaluations and statistics will be defined via this header.
*
*	Alex vanKooten
*	St#4789665
*	Updated Nov.11.2016	*/

#pragma once
class MatchMaker {
public:
	MatchMaker();
	~MatchMaker();
	/*given a board state this greedy AI will determine and return what it believes 
	 *to be it's optimal move to win the game*/ 
	int computerMove(Board &b, char piece, char enemy);
	/*evaluates a specified row*/
	void evalRow(Board &b, int row, int x, int y, int z, char testPiece, int value); 
	/*evaluates a specified diagonal*/
	void evalDiag(Board &b, int x1, int x2, int y1, int y2, char testPiece, int value); 
};


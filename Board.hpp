//
// Created by Neil on 4/13/2017.
//

#ifndef PROJECT_1_TRY_TWO_BOARD_HPP
#define PROJECT_1_TRY_TWO_BOARD_HPP

#include "Ant.hpp"
#include <iostream>

class Board {
private:
	int boardLength;
	int boardWidth;
	char** boardPtr;

	int oldX;
	int oldY;
	char oldSpace;

	Ant gameAnt;

public:
	Board();
	Board(int, int);

	void printBoard();

	void setAnt(int x, int y, char dir);

	void move();

    char getSpace();

	void clearBoard();
};


#endif //PROJECT_1_TRY_TWO_BOARD_HPP

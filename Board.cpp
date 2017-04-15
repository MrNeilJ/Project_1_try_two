//
// Created by Neil on 4/13/2017.
//

#include "Board.hpp"

// Generic Constructor if the user chooses to use the default
Board::Board() {
	boardLength = 10;
	boardWidth = 10;

	// Create the Dynamic 2D Array for the Board
	boardPtr = new char*[boardWidth];
	for (int i = 0; i < boardWidth; i++)
	{
		boardPtr[i] = new char[boardLength];
	}

	// Add Blank Spaces on the board
	for (int i = 0; i < boardWidth; i++)
	{
		for (int j = 0; j < boardLength; j++)
		{
			boardPtr[i][j] = ' ';
		}
	}

}

// Customizable Constructor if the user decides to build their own
Board::Board(int width, int length) {
	boardLength = length;
	boardWidth = width;

	// Create the Dynamic 2D Array for the Board
	boardPtr = new char*[boardLength];
	for (int i = 0; i < boardLength; i++)
	{
		boardPtr[i] = new char[boardWidth];
	}

	// Add Blank Spaces on the board
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			boardPtr[i][j] = ' ';
		}
	}
}

void Board::printBoard() {
	for(int i = 0; i < boardLength; i++)
	{
		for (int j = 0; j < boardWidth; j++)
		{
			std::cout << boardPtr[i][j];
		}
		std::cout << std::endl;
	}
}

void Board::setAnt(int x, int y, char dir) {
	gameAnt.setX(x);
	gameAnt.setY(y);
	gameAnt.setDirection(dir);

	boardPtr[y][x] = '@';
}

char Board::getSpace() {
	return boardPtr[gameAnt.getY()][gameAnt.getX()];
}

void Board::move(){
	oldX = gameAnt.getX();
	oldY = gameAnt.getY();
	oldSpace = gameAnt.getSpace();

	if (gameAnt.getDirection() == 'N')
	{
		if (oldSpace == ' ')
		{

			gameAnt.setX((oldX + 1) % boardWidth);
			gameAnt.setDirection('E');
		}
		else {
			if ((oldX - 1) < 0) {
				gameAnt.setX(boardWidth - 1);
			}
			else {
				gameAnt.setX(oldX - 1);
			}
			gameAnt.setDirection('W');
		}
	}
	else if (gameAnt.getDirection() == 'E')
	{
		if (oldSpace == ' ')
		{
			gameAnt.setY((oldY + 1) % boardLength);
			gameAnt.setDirection('S');
		}
		else
		{
			if ((oldY - 1) < 0) {
				gameAnt.setY(boardLength - 1);
			}
			else {
				gameAnt.setY(oldY - 1);
			}
			gameAnt.setDirection('N');
		}

	}
	else if  (gameAnt.getDirection() == 'S')
	{
		if (oldSpace == ' ')
		{
			if ((oldX - 1) < 0) {
				gameAnt.setX(boardWidth - 1);
			}
			else {
				gameAnt.setX(oldX - 1);
			}
			gameAnt.setDirection('W');
		}
		else
		{
			gameAnt.setX((oldX + 1) % boardWidth);
			gameAnt.setDirection('E');
		}
	}
	else
	{
		if (oldSpace == ' ')
		{
			if ((oldY - 1) < 0) {
				gameAnt.setY(boardLength - 1);
			}
			else {
				gameAnt.setY(oldY - 1);
			}
			gameAnt.setDirection('N');
		}
		else
		{
			gameAnt.setY((oldY + 1) % boardLength);
			gameAnt.setDirection('S');
		}
	}

	gameAnt.setSpace(boardPtr[gameAnt.getY()][gameAnt.getX()]);

	// Mark Ant on board
	boardPtr[gameAnt.getY()][gameAnt.getX()] = '@';

	// Mark Previous location with correct symbol
	if (oldSpace == ' ') {
		boardPtr[oldY][oldX] = '#';
	}
	else {
		boardPtr[oldY][oldX] = ' ';
	}
}

void Board::clearBoard() {
	// Delete dynamic memory
	for (int i = 0; i < boardLength; i++)
	{
		delete [] boardPtr[i];
	}

	delete [] boardPtr;

	// Set ptr to NULL to make sure it isn't accessed by accident and crash the system
	boardPtr = NULL;

}


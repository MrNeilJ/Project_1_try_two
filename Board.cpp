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
Board::Board(int length, int width) {
	boardLength = length;
	boardWidth = width;

	// Create the Dynamic 2D Array for the Board
	boardPtr = new char*[boardWidth];
	for (int i = 0; i < boardWidth; i++)
	{
		boardPtr[i] = new char[boardLength];
	}

	// Add Blank Spaces on the board
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			boardPtr[i][j] = ' ';
		}
	}
}

void Board::printBoard() {
	for(int i = 0; i < boardWidth; i++)
	{
		for (int j = 0; j < boardLength; j++)
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
			gameAnt.setX((oldX + 1) % boardLength);
			gameAnt.setDirection('E');
		}
		else
		{
			gameAnt.setX((oldX - 1) % boardLength);
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
			gameAnt.setY((oldY - 1) % boardLength);
			gameAnt.setDirection('N');
		}

	}
	else if  (gameAnt.getDirection() == 'S')
	{
		if (oldSpace == ' ')
		{
			gameAnt.setX((oldX - 1) % boardLength);
			gameAnt.setDirection('W');
		}
		else
		{
			gameAnt.setX((oldX + 1) % boardLength);
			gameAnt.setDirection('E');
		}
	}
	else
	{
		if (oldSpace == ' ')
		{
			gameAnt.setY((oldY - 1) % boardLength);
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

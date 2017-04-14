#include <iostream>
#include "Board.hpp"

int main() {
	int height = 20;
	int width  = 40;

	int boardMenu = 0;

	int antMenu = 0;
	int antX;
	int antY;

	int turns = 0;

	std::cout << "*************************************" << std::endl;
	std::cout << "*      Langton's Ant Simulator      *" << std::endl;
	std::cout << "*************************************" << std::endl;

	std::cout << " \nWelcome! No Ant's were harmed to provide this simulation!" << std::endl;
	std::cout << "Before we begin we have a few questions to ask you...\n" << std::endl;

	std::cout << "For the board design, would you like to:\n"
			  << "1) Design your own board size (choose your length and width)\n"
			  << "2) Go with the default board size (20(length) x 40(width))\n"
			  << "3) Randomize the size of the board (Board size varies between 20 and 80)\n" << std::endl;

	std::cout << "User Choice: ";


	do {
		std::cin >> boardMenu;

		if (boardMenu == 1) {
			std::cout << "Perfect! Type in the width and height you would like (separate with a space)\n" << std::endl;
			std::cin >> height;
			std::cin >> width;
		}
		else if (boardMenu == 2) {
			std::cout << "No worries, lets make life easy.\n" << std::endl;
		}
		else if (boardMenu == 3) {
			std::cout << "I see you like to live dangerously...Now Randomizing the board size.\n" << std::endl;
			height = rand() % (80 - 20 + 1) + 20;
			width = rand() % (80 - 20 + 1) + 20;
		}
		else {
			std::cout << "Whoops, looks like you typed in a weird number, try again please!\n" << std::endl;
		}
	} while (boardMenu < 1 && boardMenu > 3);

	Board boardGame(width, height);

	std::cout << "Height: " << height << std::endl;
	std::cout << "Width: " << width << "\n" << std::endl;
	std::cout << "Now where would you like the ant to begin? Choose from these options below:\n"
			  << "1) Place the ant in a specific location (separate x and y coords with a space)\n"
			  << "2) Go with the default location (middle of the board)\n"
			  << "3) Randomize the ant starting location\n" << std::endl;

	std::cout << "User Choice: ";

	do {
		std::cin >> antMenu;

		if (antMenu == 1) {
			std::cout << "Perfect! Type in the x and y you would like (separate with a space)" << std::endl;

			std::cin >> antX;
			std::cin >> antY;

			boardGame.setAnt(antX, antY, 'W');
		}
		else if (antMenu == 2) {
			std::cout << "Dead Center it is!\n" << std::endl;
			antX = width  / 2;
			antY = height / 2;

			boardGame.setAnt(antX, antY, 'W');
		}
		else if (antMenu == 3) {
			std::cout << "I see you like to live dangerously...Now Randomizing the board size.\n" << std::endl;
			antX = rand() % width;
			antY = rand() % height;

			boardGame.setAnt(antX, antY, 'W');
		}
		else {
			std::cout << "Whoops, looks like you typed in a weird number, try again please!\n" << std::endl;
		}
	} while (antMenu < 1 && antMenu > 3);

	std::cout << "Last question, I promise! How many turns would you like the ant to make?\n" << std::endl;

	std::cout << "User Choice: ";

	std::cin >> turns;

	std::cout << std::endl;

	std::cout << "Thank you for answering our quick questions...Let the farm games begin!\n" << std::endl;

	boardGame.printBoard();

	for (int i = 0; i < turns; i++) {
		boardGame.move();
		boardGame.printBoard();
	}



	return 0;
}
#include <iostream>
#include <time.h>
#include "Board.hpp"
#include "menuMaker.hpp"
#include "validator.hpp"

int main() {
	int height = 20;
	int width  = 40;

	int boardMenu = 0;

	int antMenu = 0;
	int antX;
	int antY;

	int turns = 0;
	std::string borderBlock = "";

	std::cout << "*************************************" << std::endl;
	std::cout << "*      Langton's Ant Simulator      *" << std::endl;
	std::cout << "*************************************" << std::endl;

	menuMaker firstMenu("For the board design, would you like to:",
						"Design your own board size (choose your length and width) (1 - 80)",
						"Go with the default board size (20(length) x 40(width))",
						"Randomize the size of the board (Board size varies between 20 and 80)");


	do {
		firstMenu.prompt();
		boardMenu = firstMenu.getResponse();


		if (boardMenu == 1) {
			std::cout << "Perfect! Type in the width and height you would like (separate with a space)";

			do {
				width = numberValidator();
				height = numberValidator();

				if (width < 0 || width> 80 || height< 0 || height > 80) {
					std::cout << "Values are out of bounds...try again!";
				}
			} while (width< 0 || width > 80 || height < 0 || height > 80);

		}
		else if (boardMenu == 2) {
			std::cout << "No worries, lets make life easy.\n" << std::endl;
		}
		else if (boardMenu == 3) {
			std::cout << "I see you like to live dangerously...Now Randomizing the board size.\n" << std::endl;
			srand(time(NULL));
			height = rand() % (80 - 20 + 1) + 20;
			width = rand() % (80 - 20 + 1) + 20;
		}
		else if (boardMenu == 4) {
			return 0;
		}
		else {
			std::cout << "Whoops, looks like you typed in a weird number, try again please!\n" << std::endl;
		}
	} while (boardMenu < 1 || boardMenu > 4);

	Board boardGame(width, height);

	std::cout << "Height: " << height << std::endl;
	std::cout << "Width: " << width << "\n" << std::endl;

	menuMaker menuTwo(	"Now where would you like the ant to begin? Choose from these options below:",
					  	"Place the ant in a specific location (separate x and y coords with a space) (1 - 80)",
						"Go with the default location (middle of the board)",
						"Randomize the ant starting location");

	do {
		menuTwo.prompt();
		antMenu = menuTwo.getResponse();

		if (antMenu == 1) {
			std::cout << "Perfect! Type in the x and y you would like (separate with a space)" << std::endl;

			do {
				antX = numberValidator();
				antY = numberValidator();

				if (antX < 0 ||  antX > width || antY < 0 || antY > height) {
					std::cout << "Values are out of bounds...try again!";
				}
			} while (antX < 0 || antX > width - 1 || antY < 0 || antY > height - 1);

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
			srand(time(NULL));
			antX = rand() % width;
			antY = rand() % height;

			boardGame.setAnt(antX, antY, 'W');
		}
		else if (antMenu == 4) {
			return 0;
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

	for (int i = 0; i < width; i ++ ) {
		borderBlock += '~';
	}

	boardGame.printBoard();

	std::cout << borderBlock << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < turns; i++) {
		boardGame.move();
		boardGame.printBoard();


		std::cout << std::endl;
		std::cout << borderBlock << std::endl;
		std::cout << std::endl;
	}

	boardGame.clearBoard();

	return 0;
}
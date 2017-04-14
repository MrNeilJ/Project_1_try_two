//
// Created by Neil on 4/13/2017.
//

#include "Ant.hpp"

Ant::Ant() {
	x = 10;
	y = 5;
	direction = 'W';
	space = ' ';

}


void Ant::setX(int userX) {
	x = userX;
}

void Ant::setY(int userY) {
	y = userY;
}

void Ant::setDirection(char userDir) {
	direction = userDir;
}

void Ant::setSpace(char userSpace) {
	space = userSpace;
}

int Ant::getX() {
	return x;
}

int Ant::getY() {
	return y;
}

char Ant::getDirection() {
	return direction;
}

char Ant::getSpace() {
	return space;
}




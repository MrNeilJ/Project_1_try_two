//
// Created by Neil on 4/13/2017.
//

#ifndef PROJECT_1_TRY_TWO_ANT_HPP
#define PROJECT_1_TRY_TWO_ANT_HPP


class Ant {
private:
	int x;
	int y;
	char direction;
	char space;

public:
	Ant();

	// Location Setters
	void setX(int);
	void setY(int);
	void setDirection(char);

	// Location Getters
	int getX();
	int getY();
	char getDirection();
	char getSpace();

	void setSpace(char userSpace);
};




#endif //PROJECT_1_TRY_TWO_ANT_HPP

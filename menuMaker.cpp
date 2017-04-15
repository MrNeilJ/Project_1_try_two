//
// Created by Neil Johnson on 4/14/17.
//

#include "menuMaker.hpp"
#include <limits>
#include "validator.hpp"


menuMaker::menuMaker() {

}

menuMaker::menuMaker(std::string userQues, std::string quesOne) {
    menuOne = quesOne;
	initQues = userQues;
}

menuMaker::menuMaker(std::string userQues, std::string quesOne, std::string quesTwo) {
    menuOne = quesOne;
    menuTwo = quesTwo;
	initQues = userQues;


}

menuMaker::menuMaker(std::string userQues, std::string quesOne, std::string quesTwo, std::string quesThree) {
    menuOne     = quesOne;
    menuTwo     = quesTwo;
    menuThree   = quesThree;
	initQues 	= userQues;
}

menuMaker::menuMaker(std::string userQues, std::string quesOne, std::string quesTwo,
                     std::string quesThree, std::string quesFour) {
    menuOne     = quesOne;
    menuTwo     = quesTwo;
    menuThree   = quesThree;
    menuFour    = quesFour;
	initQues 	= userQues;

}


void menuMaker::prompt() {
	int userResponse;

	do {
		int count = 1;

		std::cout << initQues << std::endl;

		if (!(menuOne == "")) {
			std::cout << "1) " << menuOne << std::endl;
			count++;
		}
		if (!(menuTwo == "")) {
			std::cout << "2) " << menuTwo << std::endl;
			count++;
		}
		if (!(menuThree == "")) {
			std::cout << "3) " << menuThree << std::endl;
			count++;
		}
		if (!(menuFour == "")) {
			std::cout << "4) " << menuFour << std::endl;
			count++;
		}
		std::cout << count << ") Quit Program." << std::endl;

		std::cout << "\nUser Choice: ";

		userResponse = numberValidator();

		if (userResponse < 0 || userResponse > getMenuSize()) {
			std::cout << "Does not match menu specifications, try again" << std::endl;
		}



	} while (userResponse < 0 || userResponse > getMenuSize());

	response = userResponse;

}

int menuMaker::getResponse() {
	return response;
}

int menuMaker::getMenuSize() {
	int count = 1;
	if (!(menuOne == "")) {
		count++;
	}
	if (!(menuTwo == "")) {
		count++;
	}
	if (!(menuThree == "")) {
		count++;
	}
	if (!(menuFour == "")) {
		count++;
	}
	return count;
}

//
// Created by Neil on 4/14/2017.
//

#include <iostream>
#include <limits>

#include "validator.hpp"
int numberValidator() {
	int userInput;
	do {

		if (!std::cin) {
			// Clear the error for the cin stream
			std::cin.clear();

			// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "I'm sorry, that was an invalid response, please try your response again." << std::endl;
		}

		std::cin >> userInput;

	} while (!std::cin);

	return userInput;
}
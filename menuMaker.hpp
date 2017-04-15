//
// Created by Neil Johnson on 4/14/17.
//

#ifndef PROJECT_1_TRY_TWO_MENUMAKER_HPP
#define PROJECT_1_TRY_TWO_MENUMAKER_HPP

#include <string>
#include <iostream>

class menuMaker {
private:
    std::string menuOne     = "";
    std::string menuTwo     = "";
    std::string menuThree   = "";
    std::string menuFour    = "";
    std::string initQues    = "";

	int response;

public:
    menuMaker();

    menuMaker(std::string initQuest, std::string quesOne);

    menuMaker(std::string initQuest, std::string quesOne, std::string quesTwo);

    menuMaker(std::string initQuest, std::string quesOne, std::string quesTwo, std::string quesThree);

    menuMaker(std::string initQuest, std::string quesOne, std::string quesTwo,
              std::string quesThree, std::string quesFour);

    void prompt();

	int getResponse();

	int getMenuSize();
};


#endif //PROJECT_1_TRY_TWO_MENUMAKER_HPP

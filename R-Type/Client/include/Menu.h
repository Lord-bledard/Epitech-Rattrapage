#ifndef R_TYPE_MENU_H
#define R_TYPE_MENU_H

#include <vector>
#include <string>
#include <iostream>

class Menu
{
private:
    std::vector<std::string> options;
    std::string askPhrase;

    void display();
public:
    Menu(std::string askPhrase, std::vector<std::string> options);
    Menu(std::string askPhrase);
    void addOption(std::string optionName);

    int getSelectedOption();
    std::string getResult();

};
#endif //R_TYPE_MENU_H

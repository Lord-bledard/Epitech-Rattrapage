#include "Menu.h"

void Menu::addOption(std::string optionName)
{
    this->options.push_back(optionName);
}


void Menu::display()
{
    std::cout << askPhrase << std::endl;
    for (int i = 0; i < this->options.size(); i++)
    {
        std::cout << i << " - " << this->options[i] << std::endl;
    }
   std::cout << "Your choice : ";
}

int Menu::getSelectedOption()
{
    std::string input;

    int selection = 0;

    this->display();
    while (!(std::cin >> selection))
    {
        std::cout << "Please select option between 1 and " << this->options.size() << std::endl;
        std::cout << askPhrase;
    };

    std::cout << std::endl;
    return selection /* display count from 1 */;
}

Menu::Menu(std::string askPhrase, std::vector<std::string> options) :
    options(options),
    askPhrase(askPhrase)
{

}

Menu::Menu(std::string askPhrase) :
    askPhrase(askPhrase)
{

}



/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Implementation for Bunker class that inherits from Space class.
******************************************************************************/
#include "bunker.hpp"
#include "menu.hpp"

/******************************************************************************
 * Description: Bunker class default constructor.
******************************************************************************/
Bunker::Bunker()
{
    name = "";
    description = "";
    radiationLevel = 0;
}

/******************************************************************************
 * Description: Bunker class constructor that takes in name, description, and
                radiation level.
******************************************************************************/
Bunker::Bunker(std::string m_name, std::string desc, int radLvl)
{
    name = m_name;
    description = desc;
    radiationLevel = radLvl;
}
/******************************************************************************
 * Description: No items are to be put into bunker space, so examine item(int)
                returns nullptr.
******************************************************************************/
std::shared_ptr<Item> Bunker::examineItem(int)
{
    return nullptr;
}
/******************************************************************************
 * Description: specialAction() function gives you choice to walk around bunker
                to get a small backstory on the bunker and give Key Card hint.
******************************************************************************/
void Bunker::specialAction()
{
    std::string walkStr = "Would you like to walk around the bunker?\n";
    walkStr += "1. Yes\n2. No\n";
    int bunkerChoice = getPositiveInt(1, 2, walkStr);

    clearScreen();

    if (bunkerChoice == 1)
    {
        std::cout << "The bunker looks heavily fortified and very safe.\n"
            << "You remember hearing rumor that Jimmy built it during the\n"
            << "cold war.  A Key Card is required to get in the bunker.\n\n";
    }
}

void Bunker::asciiArt()
{
    std::cout << "    ___________\n"
              << "   /     _      \\\n"
              << "  /     |X|      \\\n"
              << " /______|X|_______\\\n\n";
}

/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Implementation for Street class that inherits from Space class.
******************************************************************************/
#include "street.hpp"

/******************************************************************************
 * Description: Street class default constructor.
******************************************************************************/
Street::Street()
{
    name = "";
    description = "";
    radiationLevel = 0;
}

/******************************************************************************
 * Description: Street class constructor that takes in name, description, and
                radiation level.
******************************************************************************/
Street::Street(std::string m_name, std::string desc, int radLvl)
{
    name = m_name;
    description = desc;
    radiationLevel = radLvl;
}

/******************************************************************************
 * Description: No items are to be put into street Spaces, so examine item(int)
                returns nullptr.
******************************************************************************/
std::shared_ptr<Item> Street::examineItem(int)
{
    return nullptr;
}

/******************************************************************************
 * Description: specialAction() function gives you choice to walk down street
                to get a small backstory on the street you are currently at
                and a hint that you should look for a map and compass.
******************************************************************************/
void Street::specialAction()
{
    
    std::string lookStr = "Would you like to walk down the street?\n";
    lookStr += "1. Yes\n2. No\n";
    int lookChoice = getPositiveInt(1, 2, lookStr);

    if (lookChoice == 1)
    {
        if (this->getName() == "Main Street")
        {
            std::cout << "You look around Main Street and see City Hall, the\n"
                << "Post Office, and the grocery store have been completely\n"
                << "destroyed.  What is left looks like it could collapse at\n"
                << "any moment, so it is too dangerous to explore there.\n\n";
        }
        else if (this->getName() == "Dirt Road")
        {
            std::cout << "The road is so dusty, that you should bring a map\n"
                << "and compass to help you find your way.\n\n";
        }
    }
}

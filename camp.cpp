/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Implementation for Camp class that inherits from Space class.
******************************************************************************/
#include "camp.hpp"

/******************************************************************************
 * Description: Camp class default constructor.
******************************************************************************/
Camp::Camp()
{
    name = "";
    description = "";
    radiationLevel = 0;
}

/******************************************************************************
 * Description: Camp class constructor that takes in name, description, and
                radiation level.
******************************************************************************/
Camp::Camp(std::string m_name, std::string desc, int radLvl)
{
    name = m_name;
    description = desc;
    radiationLevel = radLvl;
}

/******************************************************************************
 * Description: examineItem(int) takes in the number of an item from
                searchSpace() function. It returns a shared_ptr to Item object
                to be added to player inventory.  If no item is chosen/added it
                returns nullptr.
******************************************************************************/
std::shared_ptr<Item> Camp::examineItem(int choice)
{
    if (choice == 0)
    {
        return nullptr;
    }
    std::cout << spaceItems[choice - 1]->getName()
        << " - " << spaceItems[choice - 1]->getDescription() << "\n";

    if (spaceItems[choice - 1]->getName() == "Glowing Rock")
    {
        std::string rockString = "The rock looks heavily irradiated.\n";
        rockString += "Are you sure you want to pick up the rock ?\n";
        rockString += "1. Yes\n2. No\n";
        int takeRock = getPositiveInt(1, 2, rockString);
        if (takeRock == 1)
        {
            std::shared_ptr<Item> takeItem = spaceItems[choice - 1];
            spaceItems.erase(spaceItems.begin() + choice - 1);

            return takeItem;
        }
        else
        {
            std::cout << "You leave the rock on the ground.\n\n";
            return nullptr;
        }
    }

    else
    {
        std::string takeStr = "Put Item in inventory?\n1. Yes\n2. No\n";
        int takeItem = getPositiveInt(1, 2, takeStr);
        if (takeItem == 1)
        {
            std::shared_ptr<Item> takeItem = this->spaceItems[choice - 1];
            this->spaceItems.erase(this->spaceItems.begin() + choice - 1);
            return takeItem;
        }
        else
        {
            std::cout << "You put the item back where you found it.\n";
            return nullptr;
        }
    }
}

/******************************************************************************
 * Description: specialAction() function gives you choice to walk around camp
                to get a small backstory on the campsite.
******************************************************************************/
void Camp::specialAction()
{
    std::string specialStr = "Would you like to walk around the campsite?\n";
    specialStr += "1. Yes\n2. No\n";
    int special = getPositiveInt(1, 2, specialStr);
    
    if (special == 1)
    {
        std::cout << "You walk beside the river and take in the scenery.\n"
            << "You remember playing at this river as a child.  It doesn't\n"
            << "look like anyone will be playing here for a long time.\n"
            << "The river is now devoid of all life.\n"
            << "Fish, Frogs, Bugs, everything wiped out.\n\n";
    }
}

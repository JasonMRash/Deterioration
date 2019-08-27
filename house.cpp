/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Implementation for House class that inherits from Space class.
******************************************************************************/
#include "house.hpp"
#include "menu.hpp"

/******************************************************************************
 * Description: House class default constructor.
******************************************************************************/
House::House()
{
    name = "";
    description = "";
    radiationLevel = 0;
}

/******************************************************************************
 * Description: House class constructor that takes in name, description, and
                radiation level.
******************************************************************************/
House::House(std::string m_name, std::string desc, int radLvl)
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
std::shared_ptr<Item> House::examineItem(int choice)
{
    if (choice == 0)
    {
        return nullptr;
    }
    std::cout << this->spaceItems[choice - 1]->getName()
        << " - " << this->spaceItems[choice - 1]->getDescription() << "\n\n";
   
    if (this->spaceItems[choice - 1]->getName() == "Doug")
    {
        std::cout << "You found a map.\n\n";
        this->spaceItems.erase(this->spaceItems.begin() + choice - 1);

        std::shared_ptr<Item> mapItem = std::make_shared <Item>("Map",
            "This map should be very useful.", 0,0);
        this->spaceItems.push_back(mapItem);
        std::cout << spaceItems.back()->getName() << " - "
            << spaceItems.back()->getDescription() << "\n\n";
        std::string takeStr = "Put the map in your inventory?\n";
        takeStr += "1. Yes (put map in inventory)\n";
        takeStr += "2. No (drop map on ground)\n";
        int takeMap = getPositiveInt(1, 2, takeStr);

        clearScreen();

        if (takeMap == 1)
        {
            std::shared_ptr<Item> takeItem = this->spaceItems.back();
            this->spaceItems.pop_back();
            return takeItem;
        }
        else
        {
            std::cout << "You set the map on the floor.\n\n";
            return nullptr;
        }
    }

    else
    {
        std::string takeStr = "Put item in inventory?\n1. Yes\n2. No\n";
        int takeItem = getPositiveInt(1, 2, takeStr);

        clearScreen();

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
 * Description: specialAction() function gives you choice to tour house
                to get a small backstory on the current house you are in.
******************************************************************************/
void House::specialAction()
{
    std::string cStr = "Would you like to tour the house?\n1. Yes\n2. No\n";
    int choice = getPositiveInt(1, 2, cStr);
    
    clearScreen();

    if (choice == 1)
    {
        if (this->getName() == "Your Home")
        {
            std::cout << "\nYour home is filled with movie collectibles from\n"
                << "the 1970s and 80s.  You always wish you were old enough\n"
                << "to have seen Indiana Jones and Star Wars in theaters.\n"
                << "Most of your house is in shambles.  You are lucky to be\n"
                << "alive.\n\n";
        }
        else if (this->getName() == "Doug's House")
        {
            std::cout << "\nThis is the home of FPS Doug.  An actor most \n"
                << "famous for staring on the internet TV series \"Pure\n"
                << "Pwnage\".  There are Counter Strike \"Boom Headshot!\"\n"
                << "posters all over the wall and broken keyboards litter\n"
                << "the room.\n\n";
        }
        else // Jimmy's House
        {
            std::cout << "\nThis is the home of Jimmy a famous scientist. He\n"
                << "is the owner of the secret bunker you are searching for\n."
                << "He has not been seen for 5 years.  His disappearance was\n"
                << "very suspicious.\n\n";
        }
    }
}

void House::asciiArt()
{
    if (this->getName() == "Your Home")
    {
        std::cout << "  / \\\n"
                  << " /   \\\n"
                  << "/_____\\\n"
                  << "|  _  |\n"
                  << "| |x| |\n"
                  << "| |x| |\n\n";
    }

    else if (this->getName() == "Doug's House")
    {

    }
}



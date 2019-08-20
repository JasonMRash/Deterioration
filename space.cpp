/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-9-19
 * Description: Implementation File for Space class that has derived classes 
                Bunker, Camp, House, and Street.
******************************************************************************/

#include "space.hpp"
#include "menu.hpp"

/******************************************************************************
 * Description: Space class default constructor.
******************************************************************************/
Space::Space()
{
    name = "";
    description = "";
    radiationLevel = 0;

    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
}

Space::~Space()
{
    spaceItems.clear();
}

/******************************************************************************
 * Description: Bunker class constructor that takes in name, description, and
                radiation level.
******************************************************************************/
Space::Space(std::string m_name, std::string desc, int radLvl)
{
    name = m_name;
    description = desc;
    radiationLevel = radLvl;

    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
}

/******************************************************************************
 * Description: getName() returns the name of the Space.
******************************************************************************/
std::string Space::getName()
{
    return name;
}

/******************************************************************************
 * Description: getDescription() returns the description of the Space.
******************************************************************************/
std::string Space::getDescription()
{
    return description;
}

/******************************************************************************
 * Description: getRadiationLevel() returns the radiationLevel of the Space.
******************************************************************************/
int Space::getRadiationLevel()
{
    return radiationLevel;
}

/******************************************************************************
 * Description: enterSpace() prints a message with the space name and
                description you are moving to.
******************************************************************************/
void Space::enterSpace()
{
    std::cout << "You go to " << name << ".  " << description << "\n";
}

/******************************************************************************
 * Description: getTop returns the Space* linked to top.
******************************************************************************/
Space* Space::getTop()
{
    return top;
}

/******************************************************************************
 * Description: getBottom returns the Space* linked to bottom.
******************************************************************************/
Space* Space::getBottom()
{
    return bottom;
}

/******************************************************************************
 * Description: getLeft returns the Space* linked to left.
******************************************************************************/
Space* Space::getLeft()
{
    return left;
}

/******************************************************************************
 * Description: getRight returns the Space* linked to right.
******************************************************************************/
Space* Space::getRight()
{
    return right;
}

/******************************************************************************
 * Description: checks if there are any items left in the Space.  Returns true
                if empty and false if not empty.
******************************************************************************/
bool Space::spaceItemsIsEmpty()
{
    if (this->spaceItems.empty())
    {
        return true;
    }
    return false;
}

/******************************************************************************
 * Description: link Spaces takes in pointers for Space to top, bottom, left
                and right of current space.  Links are used to move between
                spaces by using movePlayer function in Game class.
******************************************************************************/
void Space::linkSpaces(Space* t, Space* b, Space* l, Space* r)
{
    top = t;
    bottom = b;
    left = l;
    right = r;
}

/******************************************************************************
 * Description: searchSpace asks if you want to search current Space for items.
                If you do then it asks which item you would like to examine and
                returns that choice to be used by examineItem(int) function.
                If you dont want to search for items then it returns 0 which
                makes the program bypass the examineItem(int) function.
******************************************************************************/
int Space::searchSpace()
{
    std::string searchStr = "Would you like to search the area for items?\n";
    searchStr += "1. Yes\n2. No\n";
    int searchChoice = getPositiveInt(1, 2, searchStr);

    clearScreen();

    if (searchChoice == 1)
    {
        if (spaceItems.size() > 0)
        {
            std::cout << "You scavenge for loot at " << this->name
                << " and find a few interesting items.\n\n";
            for (size_t i = 0; i < spaceItems.size(); ++i)
            {
                std::cout << i + 1 << ". " << spaceItems[i]->getName() << "\n";
            }
            int choice = getPositiveInt(1, spaceItems.size(),
                "Choose an item to examine: ");

            clearScreen();

            return choice;

        }

        else
        {
            std::cout << "There is nothing left of interest at "
                << this->name << ".\n";
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

/******************************************************************************
 * Description: addItem takes in name, description, radiation resistance, and
                radiation level of an Item to create a shared_ptr of that Item
                and pushes that created Item object to the back of the
                spaceItems vector.
******************************************************************************/
void Space::addItem(std::string m_name, std::string desc, int radRes, 
    int radLvl)
{
    std::shared_ptr<Item> createItem = 
        std::make_shared<Item>(m_name, desc, radRes, radLvl);
    spaceItems.push_back(createItem);
}



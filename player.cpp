/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Implementation for Player class.
******************************************************************************/
#include "player.hpp"
#include "menu.hpp"

/******************************************************************************
 * Description: Player class default constructor.
******************************************************************************/
Player::Player()
{
    radiationResistance = 0;
    radiationPoisoning = 0;
}

/******************************************************************************
 * Description: getRadiationPoisoning() returns radiationPoisoning of Player.
******************************************************************************/
double Player::getRadiationPoisoning()
{
    return radiationPoisoning;
}

/******************************************************************************
 * Description: getRadiationResistance() returns radiationResistance of Player.
******************************************************************************/
int Player::getRadiationResistance()
{
    return radiationResistance;
}

/******************************************************************************
 * Description: addRadiationPoisoning(double) calculates the amount of
                radiation taken by the player by taking the radiation amount
                minus the radiation times the radiationResistance divided by
                100.  It then calls the checkRadiationStatus function.
******************************************************************************/
void Player::addRadiationPoisoning(double radiation)
{
    double radiationTaken = radiation - (radiation*(radiationResistance/100.0));

    radiationPoisoning += radiationTaken;
    std::cout << radiationTaken << "% added to radiation poisoning.\n";
    checkRadiationStatus();
}

/******************************************************************************
 * Description: checkRadiationStatus() prints out the current player
                radiation poisoning percentage.  If it is greater than 65 &
                less than 100 it gives the player a chance to use an item to
                survive the radiation poisoning.
******************************************************************************/
void Player::checkRadiationStatus()
{
    std::cout << "You are at " << radiationPoisoning 
        << "% radiation poisoning.\n\n";

    if (radiationPoisoning > 65 && radiationPoisoning < 100
        && (inInventory("First Aid Kit") || inInventory("Avocado")))
    {
        std::cout << "You are dangerously close to dying.\n";
        consumeItem();
        clearScreen();
    }
}

/******************************************************************************
 * Description: addItemToInventory function takes in a shared_ptr to Item
                class.  When the ptr is not null ptr it checks if the item is a
                usable item or a passive item, then puts the item in the
                correct player inventory vector as long as the inventory is not
                full.
******************************************************************************/
void Player::addItemToInventory(std::shared_ptr<Item> newItem)
{
    if (newItem != nullptr)
    {

        if (newItem->getName() == "First Aid Kit"
            || newItem->getName() == "Avocado")
        {
            if (!useInventoryFull())
            {
                useInventory.push_back(newItem);
            }
            else
            {
                std::cout << "Useable inventory full.  Cannot add item.\n\n";
            }
        }
        else
        {
            if (!passiveInventoryFull())
            {
                passiveInventory.push_back(newItem);
                radiationResistance += newItem->getRadResist();
            }
            else
            {
                std::cout << "Passive inventory full.  Cannot add item.\n";
            }
        }
    }
}

/******************************************************************************
 * Description: consumeItem function shows the items in useInventory vector and
                lets you use one of the items.
******************************************************************************/
void Player::consumeItem()
{
    if (inInventory("First Aid Kit") || inInventory("Avocado"))
    {
        bool needMedicalAid = true;
        while (needMedicalAid)
        {
            for (size_t i = 0; i < useInventory.size(); ++i)
            {
                std::cout << i + 1 << ". " << useInventory[i]->getName() 
                    << " - " << useInventory[i]->getDescription() << "\n";
            }
            int useChoice = getPositiveInt(1, useInventory.size(),
                "Which item do you want to use? ");

                radiationPoisoning += useInventory[useChoice - 1]->getRadLvl();
                useInventory.erase(useInventory.begin() + useChoice - 1);
                needMedicalAid = false;
        }
    }
    else
    {
        std::cout << "No consumable items in you inventory to reduce radiation"
            << " poisoning.\n\n";
    }
}

/******************************************************************************
 * Description: displayItemsList function displays all items in the two player
                inventories.  The passive Items and the Usable Items.
******************************************************************************/
void Player::displayItemsList()
{
    std::cout << "Your inventory currently includes the following items:\n\n";
    std::cout << "Passive Items\n";
    if (passiveInventory.empty())
    {
        std::cout << "No Passive Items.\n";
    }
    else
    {
        for (size_t i = 0; i < passiveInventory.size(); ++i)
        {
            std::cout << passiveInventory[i]->getName() << " - "
                << passiveInventory[i]->getDescription() << "\n";
        }
    }
    std::cout << "\nUsable Items\n";
    if (useInventory.empty())
    {
        std::cout << "No Usable Items.\n";
    }
    else
    {
        for (size_t i = 0; i < useInventory.size(); ++i)
        {
            std::cout << useInventory[i]->getName() << " - "
                << useInventory[i]->getDescription() << "\n";
        }
    }
    std::cout << "\n";
}

/******************************************************************************
 * Description: inInventory checks by item name if an item of that name is in
                the useInventory or the passiveInventory.  Only checks
                useInventory if searching for First Aid Kit or Avocado.
******************************************************************************/
bool Player::inInventory(std::string iname)
{
    if (iname == "First Aid Kit" || iname == "Avocado")
    {
        for (size_t i = 0; i < useInventory.size(); ++i)
        {
            if (useInventory[i]->getName() == iname)
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        for (size_t i = 0; i < passiveInventory.size(); ++i)
        {
            if (passiveInventory[i]->getName() == iname)
            {
                return true;
            }
        }
        return false;
    }
}

/******************************************************************************
 * Description: useInventoryFull checks if useInventory is full and returns
                true if full and false if not full.
******************************************************************************/
bool Player::useInventoryFull()
{
    if (useInventory.size() < MAX_USE_INVENTORY)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/******************************************************************************
 * Description: passiveInventoryFull checks if passiveInventory is full and 
                returns true if full and false if not full.
******************************************************************************/
bool Player::passiveInventoryFull()
{
    if (passiveInventory.size() < MAX_PASSIVE_INVENTORY)
    {
        return false;
    }
    else
    {
        return true;
    }
}

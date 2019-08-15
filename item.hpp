/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Header File for Item class.
******************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
private:
    std::string name;
    std::string description;
    int radiationResistance; // is for wearable items
    int radiationLevel; // is for consumable items

public:
    Item(std::string, std::string, int, int);
    std::string getName();
    std::string getDescription();
    int getRadResist();
    int getRadLvl();
};

#endif
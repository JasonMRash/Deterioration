/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Implementation for Item class.
******************************************************************************/
#include "item.hpp"

/******************************************************************************
 * Description: Item class constructor that takes in a name, description,
                radiation resitance and radiation level to set item parameters.
******************************************************************************/
Item::Item(std::string m_name, std::string desc, int radResist, int radLvl)
{
    name = m_name;
    description = desc;
    radiationResistance = radResist;
    radiationLevel = radLvl;
}
/******************************************************************************
 * Description: getName() returns the name of the item.
******************************************************************************/
std::string Item::getName()
{
    return name;
}

/******************************************************************************
 * Description: getDescription() returns the description the item.
******************************************************************************/
std::string Item::getDescription()
{
    return description;
}
/******************************************************************************
 * Description: getRadResist() returns the radiationResistance of the item.
******************************************************************************/
int Item::getRadResist()
{
    return radiationResistance;
}

/******************************************************************************
 * Description: getRadLvl() returns the radiationLevel of the item.
******************************************************************************/
int Item::getRadLvl()
{
    return radiationLevel;
}

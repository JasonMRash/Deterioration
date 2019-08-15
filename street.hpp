/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Header File for Street class that inherits from Space class.
******************************************************************************/
#ifndef STREET_HPP
#define STREET_HPP

#include "space.hpp"

#include <string>
#include <iostream>
class Street : public Space
{
public:
    Street();
    Street(std::string, std::string, int);
    std::shared_ptr<Item> examineItem(int);
    void specialAction();
};

#endif
/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Header File for House class that inherits from Space class.
******************************************************************************/
#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "space.hpp"
#include "item.hpp"
#include "validation.hpp"

#include <vector>
#include <iostream>

class House : public Space
{
public:
    House();
    House(std::string, std::string, int);
    std::shared_ptr<Item> examineItem(int);
    void specialAction();
    void asciiArt();
};

#endif
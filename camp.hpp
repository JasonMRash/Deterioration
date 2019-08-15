/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Header File for Camp class that inherits from Space class.
******************************************************************************/
#ifndef CAMP_HPP
#define CAMP_HPP

#include "space.hpp"
#include "item.hpp"
#include "validation.hpp"

#include <vector>
#include <iostream>

class Camp : public Space
{
public:
    Camp();
    Camp(std::string, std::string, int);
    std::shared_ptr<Item> examineItem(int);
    void specialAction();
};

#endif
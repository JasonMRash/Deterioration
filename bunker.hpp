/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Header File for Bunker class that inherits from Space class.
******************************************************************************/
#ifndef BUNKER_HPP
#define BUNKER_HPP

#include "space.hpp"
#include "item.hpp"
#include "validation.hpp"

#include <vector>
#include <iostream>

class Bunker: public Space
{
public:
    Bunker();
    Bunker(std::string, std::string, int);
    std::shared_ptr<Item> examineItem(int);
    void specialAction();
};

#endif
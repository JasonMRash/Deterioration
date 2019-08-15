/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-9-19
 * Description: Header File for Space class that has derived classes Bunker,
                Camp, House, and Street.
******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "item.hpp"
#include "validation.hpp"

class Space
{
protected:
    std::string name;
    std::string description;
    int radiationLevel;
    Space* top;
    Space* bottom;
    Space* left;
    Space* right;
    std::vector<std::shared_ptr<Item>> spaceItems;
public:
    Space();
    ~Space();
    Space(std::string, std::string, int);
    std::string getName();
    std::string getDescription();
    int getRadiationLevel();
    void enterSpace();
    Space* getTop();
    Space* getBottom();
    Space* getLeft();
    Space* getRight();
    bool spaceItemsIsEmpty();
    void linkSpaces(Space*, Space*, Space*, Space*);
    int searchSpace();
    void addItem(std::string, std::string, int, int);
    virtual std::shared_ptr<Item> examineItem(int) = 0; // pure virtual
    virtual void specialAction() = 0; // pure virtual
};

#endif

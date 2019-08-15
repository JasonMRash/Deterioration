/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Header File for Player class.
******************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>

#include "item.hpp"
#include "validation.hpp"

class Player
{
protected:
    const size_t MAX_USE_INVENTORY = 2;
    const size_t MAX_PASSIVE_INVENTORY = 10;

   double radiationPoisoning;
    std::vector<std::shared_ptr<Item>> passiveInventory;
    std::vector<std::shared_ptr<Item>> useInventory;
    int radiationResistance;

public:
    Player();
    double getRadiationPoisoning();
    int getRadiationResistance();
    void addRadiationPoisoning(double);
    void checkRadiationStatus();
    void addItemToInventory(std::shared_ptr<Item>);
    void consumeItem();
    void displayItemsList();
    bool inInventory(std::string);
    bool useInventoryFull();
    bool passiveInventoryFull();

};

#endif
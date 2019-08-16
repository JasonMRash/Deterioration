/******************************************************************************
 * Project Name: Final Project
 * Author: Jason Rash
 * Date: 8-9-19
 * Description: Header file for Game class that runs the game.
******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "validation.hpp"
#include "space.hpp"
#include "house.hpp"
#include "camp.hpp"
#include "street.hpp"
#include "bunker.hpp"
#include "player.hpp"


#include <iostream>
#include <string>

class Game 
{
protected:
    bool runGame;
    bool bunkerFound;
    Player* player;
    Camp river;
    Bunker bunker;
    Street dirt;
    Space* currentSpace;

public:
    Game();
    ~Game();
    void createSpaces();
    void gameIntro();
    void startGame();
    void movePlayer();
    void displayMap();
    void checkEndGame();
    void findBunker();
};


#endif

/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Implementation for Main Menu function.
******************************************************************************/
#include "menu.hpp"

/******************************************************************************
 * Description: displayMainMenu function displays the main menu and creates
                instance of Game class to create the different areas in game.
******************************************************************************/
void displayMainMenu()
{
    std::string selection = "";

    std::cout << "1. Start New Game\n"
        << "2. Exit Program\n";

    while (selection != "1" && selection != "2")
    {
        std::getline(std::cin, selection);
        if (selection == "1")
        {
            Game game;
            clearScreen();
            game.createSpaces();
        }
        else if (selection != "2")
        {
            std::cout << "Please choose option 1 or 2.\n";
        }
    }
}

void clearScreen()
{
    std::cout << std::string(100, '\n');
}

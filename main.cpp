/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-13-19
 * Description: Location of int main() The Start of the Program.
******************************************************************************/
#include "menu.hpp"

#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(NULL));
    clearScreen();
    std::cout << "DETERIORATION\n"
        << "by Jason Rash.\n\n";
    displayMainMenu();

    return 0;
}
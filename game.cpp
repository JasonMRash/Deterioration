/******************************************************************************
 * Project Name: Final Project
 * Author: Jason Rash
 * Date: 8-9-19
 * Description: Implementation of game class.
******************************************************************************/

#include "game.hpp"

/******************************************************************************
 * Description: Game class default constructor.
******************************************************************************/
Game::Game()
{
    player = new Player();
    bunkerFound = false;
    runGame = true;
    currentSpace = nullptr;
}

Game::~Game()
{
    delete player;
}

void Game::createSpaces()
{   
    House home("Your Home", "Home Sweet Home.", 10);
    home.addItem("OSU Hat", "Increases your physical appearance.", 0, 0);
    home.addItem("First Aid Kit", "Reduces radiation poisoning by 25 (-25%)."
        , 0, -25);
    home.addItem("Muck Boots", "Increases radiation resistance. (+10% resist)"
        , 10, 0);

    House doug("Doug's House", "Your Neighbor FPS Doug's House.", 10);
    std::string knifeDesc = "Everyone runs faster with a knife. (+5% resist)";
    doug.addItem("Knife", knifeDesc, 5, 0);
    doug.addItem("Doug", "His body lay lifeless under a desk.", 0, 0);

    doug.addItem("Avocado", "Reduces radiation poisoning by 75 (-75%)."
        , 0, -75);

    House jimmy("Jimmy's House", "Home of a scientist named Jimmy.", 10);
    jimmy.addItem("Rain Coat", "Increases radiation resistance.(+10% resist)"
        , 10, 0);
    jimmy.addItem("Key Card", "Looks like a Key for something.", 0, 0);
    jimmy.addItem("First Aid Kit", "Reduces radiation poisoning by 25 (-25%)."
        , 0, -25);
    Camp river("Riverside Camp", "A dilapidated campground.", 15);
    river.addItem("Compass", "Should help point you where to go", 0, 0);
    river.addItem("Glowing Rock", "A bright neon orange rock. (-50% resist)",
        -50, 0);
    river.addItem("First Aid Kit", "Reduces radiation poisoning by 25 (-25%)."
        , 0, -25);
    Street mainS("Main Street", "Main Street Circleville,KS. Pop 163", 20);
    Street dirt("Dirt Road", "The Long and Winding Road.", 15);
    Bunker bunker("Bunker", "A tightly sealed radiation proof bunker.", 0);
    home.linkSpaces(&mainS, nullptr, nullptr, nullptr);
    doug.linkSpaces(nullptr, &mainS, nullptr, nullptr);
    jimmy.linkSpaces(nullptr, nullptr, &river, nullptr);
    river.linkSpaces(nullptr, &dirt, &mainS, &jimmy);
    mainS.linkSpaces(&doug, &home, nullptr, &river);
    dirt.linkSpaces(&river, &bunker, nullptr, nullptr);
    bunker.linkSpaces(&dirt, nullptr, nullptr, nullptr);
    currentSpace = &home;
    gameIntro();
    startGame();
}

void Game::gameIntro()
{
    std::cout << "The air raid sirens sounded a couple hours ago.  A giant \n"
        << "mushroom cloud formed right outside of town and you ran to your \n"
        << "house as fast as you could.  You did the only thing you could \n"
        << "think of and get into the refrigerator like you saw in an old \n"
        << "Indiana Jones movie.\n\n"
        << "As you crawl out of the refridgerator you are surprised your\n"
        << "house is still standing.  You remember hearing about a cold war\n"
        << "bunker located somewhere near by, but don't know how to get \n"
        << "there.\n\n"
        << "Your objective is to get to the bunker to survive the radiation.\n"
        << "Maybe you can dig up some information around town.\n\n";
}


void Game::startGame()
{
    while (runGame)
    {
        currentSpace->enterSpace();
        player->addRadiationPoisoning(currentSpace->getRadiationLevel());
        findBunker();
        checkEndGame();
        if (runGame)
        {
            currentSpace->specialAction();
            bool searchSpace = true;
            while (searchSpace && !currentSpace->spaceItemsIsEmpty())
            {
                int itemChoice = currentSpace->searchSpace();
                if (itemChoice == 0)
                {
                    searchSpace = false;
                }
                else
                {
                    std::shared_ptr<Item> takeItem = currentSpace->examineItem(itemChoice);
                    player->addItemToInventory(takeItem);
                    player->displayItemsList();

                    if (currentSpace->spaceItemsIsEmpty())
                    {
                        std::cout << "No Items left at " << currentSpace->getName()
                            << "\n\n";
                        searchSpace = false;
                    }
                }
            }
            displayMap();
            movePlayer();
        }
        else
        {
            displayMainMenu();
        }
    }
}

void Game::movePlayer()
{
    bool validMove = false;
    while (!validMove)
    {
        std::string moveStr = "Which way would you like to move?\n";
        moveStr += "You are currently at " + currentSpace->getName() + ".\n";
        moveStr += "1. Move Up\t2. Move Down\n";
        moveStr += "3. Move Left\t4. Move Right\n";

        int move = getPositiveInt(1, 4, moveStr);

        if (move == 1)
        {
            if (currentSpace->getTop() != nullptr)
            {
                validMove = true;
                currentSpace = currentSpace->getTop();
                std::cout << "Now moving to " << currentSpace->getName()
                    << "\n\n";
            }
            else
            {
                std::cout << "Cannot move Up.  Chose another direction.\n";
            }
        }
        else if (move == 2)
        {
            if (currentSpace->getBottom() != nullptr)
            {
                validMove = true;
                currentSpace = currentSpace->getBottom();
                std::cout << "Now moving to " << currentSpace->getName()
                    << "\n\n";
            }
            else
            {
                std::cout << "Cannot move Down.  Chose another direction.\n";
            }
        }
        else if (move == 3)
        {
            if (currentSpace->getLeft() != nullptr)
            {
                validMove = true;
                currentSpace = currentSpace->getLeft();
                std::cout << "Now moving to " << currentSpace->getName()
                    << "\n\n";
            }
            else
            {
                std::cout << "Cannot move Left.  Chose another direction.\n";
            }
        }
        else
        {
            if (currentSpace->getRight() != nullptr)
            {
                validMove = true;
                currentSpace = currentSpace->getRight();
                std::cout << "Now moving to " << currentSpace->getName()
                    << "\n\n";
            }
            else
            {
                std::cout << "Cannot move Right.  Chose another direction.\n";
            }
        }
    }
}

void Game::displayMap()
{   
    if (!bunkerFound)
    {
        std::cout << "Doug's House\n"
            << "     |\n"
            << "Main Street----Riverside Camp----Jimmy's House\n"
            << "     |               |\n"
            << "Your House       Dirt Road\n\n";
    }
    else
    {
        std::cout << "Doug's House\n"
            << "     |\n"
            << "Main Street----Riverside Camp----Jimmy's House\n"
            << "     |               |\n"
            << "Your House       Dirt Road\n"
            << "                     |\n"
            << "                   BUNKER\n\n";
    }
}

void Game::checkEndGame()
{
    if (player->getRadiationPoisoning() >= 100)
    {
        std::cout << "You get lightheaded and fall over.  The radiation has\n "
            << "taken its toll on your body.Your breathing gets shallow. You\n"
            << "look up into the yellow-orange sky above and contemplate if\n"
            << "humanity will survive.  You take one last breath and close\n"
            << "your eyes.\n\n."
            << "THE END\n\n";
        runGame = false;
    }
    else if (currentSpace->getName() == "Bunker")
    {
        if (player->inInventory("Key Card"))
        {
            std::cout << "You use the Key Card to open up the Bunker.\n"
                << "You find a massive stockpile of food, water, and medical\n"
                << "supplies to cure you of your radiation poisoning.\n\n"
                << "Will you be a reclusive bunker dweller or go out and fix\n"
                << "this broken world?\n\n"
                << "THE END\n\n";
            runGame = false;
        }
        else
        {
            std::cout << "You need a Key Card to get in the Bunker.\n";
        }
    }
}

void Game::findBunker()
{
    if (player->inInventory("Map")
        && player->inInventory("Compass") && bunkerFound == false)
    {
        std::cout << "You use your map and compass you locate a trail\n"
            << "leading to the bunker! Bunker location added to map.\n\n";
        bunkerFound = true;
    }
}

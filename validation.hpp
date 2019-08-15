/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-9-19
 * Description: Validation functions header file.  Functions are for input
 *              validation to check if user input is of the correct type
 *              for the program to function correctly.
******************************************************************************/

#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <string>
#include <iostream>
#include <cstdlib> //for srand & rand

int getInt(std::string prompt);
int getPositiveInt(int min, int max, std::string prompt);
bool isInt(std::string str);
bool isPositiveInt(std::string str);
int getRandNum(int min, int max);
std::string getString(std::string prompt);

#endif

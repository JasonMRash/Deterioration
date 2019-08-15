/******************************************************************************
 * Program name: Final Project Text Based Game
 * Author: Jason Rash
 * Date: 8-9-19
 * Description: Validation functions used to validate user input values are
 *              of the correct type for the program to function correctly.
******************************************************************************/

#include "validation.hpp"

/******************************************************************************
 * Description: The getInt(std::string) function takes in a string to use for
 *              the prompt to tell the user what to input. The function gets
 *              a string from the user and uses the isInt function to check if 
 *              it is an integer value.  It then converts a valid integer value
 *              from a string to an integer.
******************************************************************************/

int getInt(std::string prompt)
{    
    std::string str = "";
    int num = 0;
    
    while (!isInt(str) || str.empty())
    {
        std::cout << prompt;
        std::getline(std::cin, str);

        if (isInt(str))
        {       
            // Convert string to integer value
            for (size_t i = 0; i < str.length(); ++i)
            {
                if (str[i] != '-')
                {
                    num = num * 10 + (str[i] - '0');
                }
            }
        }
        else
        {
            std::cout << "Input is either too long or not a number.\n";
        }
    }
    // if string has a negative sign at 0 index num is negative
    if (str[0] == '-')
    {
        num = -num;
    }

    return num;
}

/******************************************************************************
 * Description: getPositiveInt(int, int, std::string ) function checks for if
                input from the user is an integer within a specified range. The
                function has three parameters, the minimum range of integer,
                the maximum range of integer, and a string that is the prompt
                given to the user saying what type of data the function is 
                asking for.  It keeps asking the user for input until a valid 
                integer value within the given range.  The string is then 
                converted to an integer.  
                
                NOTE: int min parameter must be >= 0.
******************************************************************************/

int getPositiveInt(int min, int max, std::string prompt)
{
    std::string str = "";
    int num = 0;
    bool withinRange = false;

    while (!isPositiveInt(str) || str.empty() || !withinRange)
    {
        num = 0;
        std::cout << prompt;
        std::getline(std::cin, str);

        if (isPositiveInt(str) && !str.empty())
        {
            // Convert string to integer value
            for (size_t i = 0; i < str.length(); ++i)
            {
                    num = num * 10 + (str[i] - '0');
            }


            // Check if integer is within range specified by min and max
            if (num < min || num > max)
            {
                std::cout << "Number must " << min
                          << " through " << max << ".\n";
            }
            else
            {
                withinRange = true;
            }
        }
        else
        {
            std::cout << "Input is either too long or not a positive number.\n"
                      << "Number must be " << min
                      << " through " << max << ".\n";
        }
    }

    return num;
}

/******************************************************************************
 * Description: IsPositiveInt(std::string) checks that only numbers are
                present. Int range is normally -2,147,483,648 to 2,147,483,647.
                To avoid overflow I made it so the max it would take in would 
                be 999,999,999 (9 digits) while I look into a cleaner way to do
                this.
******************************************************************************/

bool isPositiveInt(std::string str)
{
    if (str.empty())
    {
        return false;
    }

    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (i > 8) // positive int close to overflow
            {
                return false;
            }
        }
        else // when input is not a number
        {
            return false;
        }
    }
    return true;
}
/******************************************************************************
 * Description: Is int(std::string) first checks for a - sign at the beginning,
                then if there are only digits present after that.  Int range is
                normally -2,147,483,648 to 2,147,483,647.  To avoid overflow I 
                made it so the max it would take in would be -999,999,999 
                (10 digits) or 999,999,999 (9 digits) while I look into a 
                cleaner way to do this.
******************************************************************************/

bool isInt(std::string str)
{
    if (str.empty())
    {
        return false;
    }

    for (size_t i = 0; i < str.length(); ++i)
    {
        if ((i == 0 && str[i] == '-') || (str[i] >= '0' && str[i] <= '9'))
        {
            if (str[0] == '-' && i > 9) // negative int close to overflow
            {
                return false;
            }
            else if (i > 8) // positive int close to overflow
            {
                return false;
            }
        }
        else // when input is not a number or - sign at 0 index
        {
            return false;
        }
    }
    return true;
}

/******************************************************************************
 * Description: The getRandomNum(int, int) function takes in a min and max into
 *              the function and returns a pseudo random integer value using 
 *              rand.
******************************************************************************/

int getRandNum(int min, int max)
{

    // Formula for this function is from Chapter 3.10 Random Numbers in 
    // Starting Out with C++ Early Objects by Gaddis et al. (page 135)
    int randomNumber = (rand() % (max - min + 1)) + min;

    return randomNumber;
}

/******************************************************************************
 * Description: getString takes in a string to prompt the user for input. A
                string is taken from the user using getline to include all
                input.  The string from the user is returned.
******************************************************************************/

std::string getString(std::string prompt)
{
    std::string str = "";
    std::cout << prompt;
    std::getline(std::cin, str);

    return str;
}

//
//  main.cpp
//  cdChecker
//
//  Created by Max Huber on 2/21/13.
//  Copyright (c) 2013 S0URC3 Studioss. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

int rollDice(int);
int diceCheck(int diceMod, int dci, int roll);
void clearScreen();
void pressEnter();
void dcFunction();


int main()
{
    dcFunction();
    clearScreen();
    main();
}

// Roll a n sided die
int rollDice(int sides)
{
    //int gen;

    //create time variable
    time_t timer;

    //set time variable to current time in seconds
    time(&timer);

    //seed random number generator using current time in seconds
    srand(timer);

    //generate random number
    //gen = (rand()% sides + 1);

    return(rand()% sides + 1);
}

// Check if the dice roll + modifier (if any) is greater than the check value
int diceCheck(int diceMod, int dci, int roll)
{
    if(roll + diceMod >= dci)
    {
        return 0;
    }
    else
        return 1;
}

void clearScreen()
{
    #ifdef _WIN32
        std::system ( "CLS" );

    #else
        // Assume POSIX
        std::system ( "clear" );
    #endif
}
void pressEnter()
{
    std::cin.sync();
    std::cout << std::endl << "Press ENTER to continue..." << std::endl;
    std::cin.get();
}

void dcFunction()
{
    //define variables
    int neededRoll;
    int diceMod;
    int sides;
    int roll;

    //get user inputs
    std::cout << "How many sides: ";
    std::cin >> sides;
    std::cout << "Enter needed roll: ";
    std::cin >> neededRoll;
    std::cout << "Enter dice modifiers: ";
    std::cin >> diceMod;

    //store roll in variable so it can be gotten later
    roll = rollDice(sides);

    //check if your roll was better than the dice check

    //success check
    if(diceCheck(diceMod, neededRoll, roll) == 0)
    {
        std::cout << "\nSUCCESS\n\n"
        << "You rolled a " << sides << " sided die\n"
        << "You rolled: " << roll << " + " << diceMod << " = " << roll + diceMod << "\n"
        << "You needed: " << neededRoll << "\n";
    }

    //otherwise you fail
    else
    {

        std::cout << "\nFAILURE!!!\n\n"
        << "You rolled a " << sides << " sided die\n"
        << "You rolled: " << roll << " + " << diceMod << " = " << roll + diceMod << "\n"
        << "You needed: " << neededRoll << "\n";
    }
    pressEnter();
}

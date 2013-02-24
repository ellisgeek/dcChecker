//
//  main.cpp
//  cdChecker
//
//  Created by Max Huber on 2/21/13.
//  Copyright (c) 2013 IDEAS. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

int rollDice(int sides);
int diceCheck(int diceMod, int dci, int roll);


int main(int argc, const char * argv[])
{
    int neededRoll;
    int diceMod;
    int sides;
    int roll;

    // insert code here...
    std::cout << "How many sides: ";
    std::cin >> sides;
    std::cout << "Enter needed roll: ";
    std::cin >> neededRoll;
    std::cout << "Enter dice modifiers: ";
    std::cin >> diceMod;

    roll = rollDice(sides);

    if(diceCheck(diceMod, neededRoll, roll) == 0)
    {
        std::cout << "\nSUCCESS\n\n"
                  << "You rolled a " << sides << " sided die\n"
                  << "You rolled: " << roll << " + " << diceMod << " = " << roll + diceMod << "\n"
                  << "You needed: " << neededRoll << "\n";
    }
    else
    {
        std::cout << "\nFAILURE!!!\n\n"
                  << "You rolled a " << sides << " sided die\n"
                  << "You rolled: " << roll << " + " << diceMod << " = " << roll + diceMod << "\n"
                  << "You needed: " << neededRoll << "\n";
    }
    return 0;
}

int rollDice(int sides)
{
    int gen;
    time_t timer;
    time(&timer);
    srand(timer);
    gen = (rand()% sides + 1); //roll 20 sided die
    return gen;
}

int diceCheck(int diceMod, int dci, int roll)
{
    if(roll + diceMod >= dci)
    {
        return 0;
    }
    else
        return 1;
}


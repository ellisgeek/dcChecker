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
#include <limits>

int rollDie(int sides);
int diceCheck(int diceMod, int dci, int roll);
void clearScreen();
void pressEnter();
void dcFunction();
void diceRoller(int numDice, int sides);
void menu();

int main()
{
  //int gen;

    //create time variable
    time_t timer;

    //set time variable to current time in seconds
    time(&timer);

    //seed random number generator using current time in seconds
    srand(timer);

    //Load Menu
    menu();
}

// Roll a n sided die
int rollDie(int sides)
{
    //generate random number
    //gen = (rand()% sides + 1);
    int rnumber = rand();
    return(rnumber% sides + 1);
    srand(rnumber);
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

//Clear the screen
void clearScreen()
{
#ifdef _WIN32
    std::system ( "CLS" );

#else
    // Assume POSIX
    std::system ( "clear" );
#endif
}

//Wait for the user to press ENTER
void pressEnter()
{
    std::cin.ignore();
    std::cout << "\nPress ENTER to Continue";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

//Dice Check function
void dcFunction()
{
    //define variables
    int neededRoll;
    int diceMod;
    int sides;
    int roll;

    //Clear Screen
    clearScreen();

    //get user inputs
    std::cout << "How many sides: ";
    std::cin >> sides;
    std::cout << "Enter needed roll: ";
    std::cin >> neededRoll;
    std::cout << "Enter dice modifiers: ";
    std::cin >> diceMod;

    //store roll in variable so it can be gotten later
    roll = rollDie(sides);

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
    main();
}

void diceRoller()
{
  int numDice;
  int numSides;
  int numRolled = 0;

  //get user inputs
    std::cout << "How many dice: ";
    std::cin >> numDice;
    std::cout << "How mane sides: ";
    std::cin >> numSides;

  while(numRolled < numDice)
    {
    std::cout << rollDie(numSides) << "\n";
    numRolled++;
    }
  pressEnter();
  main();
}

void menu()
{
    do
    {
        clearScreen();
        int input;
        std::cout << "\n\n\n\n\n\nEnter the number that corrisponds to the menu entry that you want!\n\n";

        //Add menu entries to this cout!
        std::cout << " ________________\n"
                  << "|                |\n"
                  << "| 1 - Dice Check |\n"
                  << "| 2 - Roll Dice  |\n"
                  << "| 3 - Exit       |\n"
                  << "|________________|\n\n";
        std::cout << "Selection: ";
        std::cin >> input;
        switch(input)
        {
        case (1):
            dcFunction();
        case (2):
            diceRoller();
        case (3):
            exit(0);
        }
    }
    while(true);
}


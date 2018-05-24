#ifndef MENU_H
#define MENU_H

#include "Database.h"
#include "Database.cpp"

#include "WordBank.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Menu
{
    public:
        Menu();
        virtual ~Menu();

        //The main menu of the program
        void menu();

        //Allows the player to add a word to the wordbank
        void addWord();

        //Displays the scores stored in the text file
        void displayScores();

        //Checks if the command is valid
        bool validCommand(string& command);

        //Scans the word bank and returns false if a word already exists
        bool wordAlreadyExists(string word);

        //Checks if a name and score has already been displayed
        //Prevents the highscore from displaying as both the highscore and a regular score
        bool checkForDuplicate(int i, Menu highscore);

    private:
        string command;
        string name;

        int score;
        int numberOfGames;

        char anyKey;
        vector<Menu> scores;
};

#endif // MENU_H

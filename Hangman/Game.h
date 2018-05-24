#ifndef GAME_H
#define GAME_H

#include "WordBank.h"
#include "WordBank.cpp"

#include "Database.h"

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

class GameOverClass{};
class WinnerClass{};

using namespace std;

class Game
{
    public:
        Game(int pts);
        virtual ~Game();

        //Selects random word from the vector,
        void wordSelection();

        //The "main" fuction of the class
        void gameOn();

        //Displays the dashes, letters guessed, correct letters and how many tries
        //the player has left
        void displayMenu();

        //Stores the correct letters into an array to use for the displayMenu function
        void assignLettersGuessed(char guess);

        //Checks if the player has either won or lost, throws exception if so
        void gameOverCheck();

        //Displays the vector and array, for testing purposes only,
        void displayTest();

        //Calls a function in the Database class that saves the score and name to a text file
        void saveScoreToDatabase(string name, int numberOfGames);

        //Allows the player to input how many tries they'll get
        void howManyTries();

        //This function is called when the player tries to guess an entire word
        void guessWord();


        //Returns the correct word
        string wordGet();

        //Returns points
        int pointGet();

        //Return how many wrong tries the player got
        int wrongCounterGet();

        //Returns char input by the player
        char playerGuess();

        //Checks if the player guessed a letter correctly
        bool validLetter(char playerGuess);

        //Checks if the player guessed the word correctly
        bool correctWord(string wordGuess);

    private:
        WordBank wb;
        Database db;

        int tries;
        int count;
        int points;
        int wrongCounter;

        string word;

        char guess;
        const char* letters;
        char* lettersGuessed;

        vector<string> wordVector;
        vector<char> wrongLetters;
};

#endif // GAME_H

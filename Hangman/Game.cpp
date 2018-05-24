#include "Game.h"

Game::Game(int pts)
{
    wordVector = wb.initializeWordBank();
    wordSelection();
    points = pts;
    count = 0;
    wrongCounter = 0;
}

Game::~Game()
{
    delete[] letters;
    delete[] lettersGuessed;
}

void Game::wordSelection()
{
    //Creates a random number
    srand(time(0));
    int randomNum = rand()%wordVector.size();

    //Assigns the element in the random vector number to word
    word = wordVector[randomNum];

    //Creates dynamic array where the correct letters guessed are stored
    lettersGuessed = new char[word.size()];

    //Creates char array of word
    letters = word.c_str();
}

void Game::gameOn()
{
    displayMenu();
    guess = playerGuess();

    if(guess == '-')
    {
        guessWord();
    }

    bool valid = validLetter(guess);

    if(!valid)
    {
        //Checks if the wrong letter has already been guessed and throws exception if that's the case
        //otherwise it decreases tries by one and stores the letter into a vector
        for(int i = 0; i < wrongLetters.size(); i++)
        {
            if(guess == wrongLetters[i])
            {
                char anyKey;

                cout << "\nYou've already guessed that! " << endl;
                cout << "Press any key to continue: ";
                cin >> anyKey;

                gameOn();
            }
        }

        tries--;
        wrongCounter++;
        wrongLetters.push_back(guess);
    }

    else
    {
        assignLettersGuessed(guess);
    }

    gameOverCheck();

    gameOn();
}

char Game::playerGuess()
{
    char playersGuess;

    cout << "\nGuess letter: ";
    cin >> playersGuess;

    /*
    if(playersGuess.length() > 1)
    {
        cout << "\nInput only one letter!" << endl;
        playerGuess();
    }*/

    return playersGuess;
}

void Game::assignLettersGuessed(char guess)
{
    //Stores the player's guess in an array to use in the displayMenu function
    //Increments count for every letter stored, rather than every right guess, important for words with two of
    //the same letter like "school"
    for(int i = 0; i < word.size(); i++)
    {
        if(letters[i] == guess)
        {
            lettersGuessed[i] = letters[i];
            count++;
        }
    }
}

void Game::displayMenu()
{
    //Clears the screen
    system("cls");

    cout << "\tHangman" << endl;

    for(int i = 0; i < 24; i++)
    {
        cout << "=";
    }

    cout << "\n\n";

    for(int i = 0; i < word.size(); i++)
    {
        if(letters[i] == lettersGuessed[i])
        {
            cout << " " << letters[i] << " ";
        }

        else
        {
            cout << " - ";
        }
    }

    cout << "\n" << endl;

    for(int i = 0; i < 24; i++)
    {
        cout << "=";
    }

    cout << "\nTries left: " << tries << "\t\t\t\t";

    for(int i = 0; i < wrongLetters.size(); i++)
    {
        cout << wrongLetters[i] << " ";
    }

    cout << "\n\nPoints: " << points << endl;
}


void Game::gameOverCheck()
{
    if(tries == 0)
    {
        displayMenu();
        throw GameOverClass();
    }

    //The value of count corresponds to the size of the lettersGuessed array
    //as shown in the assignLettersGuessed array
    if(count == word.size())
    {
        displayMenu();
        throw WinnerClass();
    }
}

void Game::displayTest()
{
    //This function is only used to test if the vector and letters array were
    //properly initialized

    //Displays the vector
    for(int i = 0; i < wordVector.size(); i++)
    {
        cout << wordVector[i] << endl;
    }

    //Displays the array of letters
    for(int i = 0; i < word.size(); i++)
    {
        cout << letters[i];
    }
}

void Game::howManyTries()
{
    cout << "\nHow many guesses do you want to have? ";
    cin >> tries;
}

void Game::saveScoreToDatabase(string name, int numberOfGames)
{
    db.saveScore(name, points, numberOfGames);
}

void Game::guessWord()
{
    string wordGuess;

    cout << "\nInput word: ";
    cin >> wordGuess;

    bool correct = correctWord(wordGuess);

    if(correct)
    {
        for(int i = 0; i < word.size(); i++)
        {
            lettersGuessed[i] = letters[i];
        }

        displayMenu();
        throw WinnerClass();
    }

    else
    {
        throw GameOverClass();
    }
}


string Game::wordGet()
{
    return word;
}

int Game::wrongCounterGet()
{
    return wrongCounter;
}

int Game::pointGet()
{
    return points;
}

bool Game::correctWord(string wordGuess)
{
    if(wordGuess == word)
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool Game::validLetter(char playerGuess)
{
    //Scans for a letter in the array that matches the player's guess
    //and returns true if it's found
    for(int i = 0; i < word.size(); i++)
    {
        if(letters[i] == playerGuess)
        {
            return true;
        }
    }

    return false;
}

#include "Menu.h"

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

void Menu::menu()
{
    system("cls");
    cout << "Welcome to hangman! \n" << endl;
    cout << "Available Commands: " << endl;
    cout << "===================" << endl;
    cout << "'play'\t\t-plays game" << endl;
    cout << "'add'\t\t-adds word to word bank" << endl;
    cout << "'display'\t-displays scores" << endl;
    cin >> command;

    bool valid = validCommand(command);

    if(!valid)
    {
        system("cls");
        cout << "\nEnter valid command!" << endl;
        menu();
    }

    if(command == "Play" || command == "play")
    {
        return;
    }

    else if(command == "Add" || command == "add")
    {
        addWord();
    }

    else if(command == "Display" || command == "display")
    {
        displayScores();
    }
}

void Menu::addWord()
{
    ofstream addToFile;
    string word;

    cout << "\nInput word to add: ";
    cin >> word;

    bool valid = wordAlreadyExists(word);

    if(!valid)
    {
        cout << "\nThat word already exists!" << endl;
        addWord();
    }

    else
    {
        addToFile.open("Words.txt", ios::app);

        addToFile << "\n\n" << word;

        addToFile.close();

        cout << "\n'" << word << "'" << " was added to the wordbank" << endl;
    }

    cout << "\nPress any key to continue: ";
    cin >> anyKey;

    system("cls");
    menu();
}

void Menu::displayScores()
{
    ifstream readScores;

    readScores.open("Scores.txt", ios::app);

    Menu highscore;
    Menu m;

    system("cls");

    cout << "===Scores===" << endl;

    while(readScores.good())
    {
        readScores >> m.name >> m.score >> m.numberOfGames;
        scores.push_back(m);
    }

    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i].score > scores[i-1].score)
        {
            highscore.score = scores[i].score;
            highscore.name = scores[i].name;
            highscore.numberOfGames = scores[i].numberOfGames;
        }
    }

    if(scores.size() == 1)
    {
        cout << "\nHigh Score: " << endl;
        cout << "Name: " << scores[0].name << endl;
        cout << "Score: " << scores[0].score << endl;
        cout << "Games: " << scores[0].numberOfGames << endl;
    }

    else if(scores.empty())
    {
        cout << "No scores available :(" << endl;
    }

    else if(scores.size() > 1)
    {
        cout << "\nHigh Score " << endl;
        cout << "=============" << endl;
        cout << "Name: " << highscore.name << endl;
        cout << "Score: " << highscore.score << endl;
        cout << "Games: " << highscore.numberOfGames << endl;
        cout << "=============" << endl;


        for(int i = 0; i < scores.size(); i++)
        {
            bool duplicate = checkForDuplicate(i, highscore);

            //Prevents the high score from being displayed twice
            if(!duplicate)
            {
                cout << "\nName: " << scores[i].name << endl;
                cout << "Score: " << scores[i].score << endl;
                cout << "Games: " << scores[i].numberOfGames << endl;
            }
        }
    }

    cout << "\nPress any key to continue: ";
    cin >> anyKey;
    menu();
}

bool Menu::wordAlreadyExists(string word)
{
    ifstream file;
    string fileWord;

    file.open("Words.txt", ios::app);

    while(file.good())
    {
        file >> fileWord;
        if(fileWord == word)
        {
            file.close();
            return false;
        }
    }

    return true;
}

bool Menu::validCommand(string& command)
{
    if(command == "Add" || command == "add" || command == "Display" || command == "display" || command == "Play" || command == "play")
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool Menu::checkForDuplicate(int i, Menu highscore)
{
    if(scores[i].name != highscore.name && scores[i].score != highscore.score && scores[i].numberOfGames != highscore.numberOfGames)
    {
        return false;
    }

    else
    {
        return true;
    }
}

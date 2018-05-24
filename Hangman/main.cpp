#include "game.h"
#include "game.cpp"

#include "menu.h"
#include "menu.cpp"

#include <iostream>

using namespace std;

bool playAgain(char again);

int main()
{
    //Idea: remove the displayMenu function and overload the << operator instead?
    int points = 0;
    int numberOfGames = 0;
    Game g(points);
    Menu m;

    try
    {
        m.menu();
        g.howManyTries();
        g.gameOn();
    }

    catch(GameOverClass)
    {
        char again;
        numberOfGames++;

        cout << "\nGame Over!" << endl;
        cout << "The word was: " << g.wordGet() << endl;
        cout << "Play again (Y/N)?: ";
        cin >> again;

        bool play = playAgain(again);

        if(play)
        {
            string name;

            cout << "Enter name: ";
            cin >> name;

            g.saveScoreToDatabase(name, numberOfGames);

            main();
        }

        else
        {
            string name;

            cout << "\nThanks for playing!" << endl;
            cout << "Enter name: ";
            cin >> name;

            g.saveScoreToDatabase(name, numberOfGames);

            return 0;
        }
    }

    catch(WinnerClass)
    {
        numberOfGames++;

        char again;

        cout << "\nYou win! Points: " << g.pointGet() << " + 100 (- " << g.wrongCounterGet() * 10 << ")" << endl;
        cout << "Play again (Y/N)?: ";

        points += 100 - (g.wrongCounterGet() * 10);
        Game game(points);

        cin >> again;

        bool play = playAgain(again);

        if(play)
        {
            game.howManyTries();
            game.gameOn();
        }

        else
        {
            string name;

            cout << "\nThanks for playing!" << endl;
            cout << "Enter name: ";
            cin >> name;

            g.saveScoreToDatabase(name, numberOfGames);

            return 0;
        }
    }


}

bool playAgain(char again)
{
    if(again == 'Y' || again == 'y')
    {
        return true;
    }

    else
    {
        return false;
    }
}

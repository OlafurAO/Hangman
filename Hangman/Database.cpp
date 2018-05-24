#include "Database.h"

Database::Database()
{
    //ctor
}

Database::~Database()
{
    //dtor
}

void Database::saveScore(string name, int score, int numberOfGames)
{
    ofstream file;

    file.open("Scores.txt", ios::app);

    file << name << endl;
    file << score << endl;
    file << numberOfGames << endl;

    file.close();
}

#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <string>

using namespace std;

class Database
{
    public:
        Database();
        virtual ~Database();

        //Saves the name and score to a text file
        void saveScore(string name, int score, int numberOfGames);

    protected:

    private:
};

#endif // DATABASE_H

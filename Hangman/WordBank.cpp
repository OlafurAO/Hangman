#include "WordBank.h"

WordBank::WordBank()
{
    //ctor
}

WordBank::~WordBank()
{
    //dtor
}

vector<string> WordBank::initializeWordBank()
{
    ifstream file;

    file.open("Words.txt", ios::app);

    while(file.good())
    {
        file >> fileWord;

        words.push_back(fileWord);
    }

    file.close();

    return words;
}

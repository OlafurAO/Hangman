#ifndef WORDBANK_H
#define WORDBANK_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class WordBank
{
    public:
        WordBank();
        virtual ~WordBank();

        //Reads words from a text file, stores them in a vector and returns the vector
        vector<string> initializeWordBank();

    private:
        string fileWord;
        vector<string> words;


};

#endif // WORDBANK_H

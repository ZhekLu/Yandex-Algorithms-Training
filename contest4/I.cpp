#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string toLower(const string& str)
{
    string lower = "";
    for(int i = 0; i < str.length(); i++)
        lower += tolower(str[i]);
    return lower;
}

int StressCount(const string& str)
{
    int counter = 0;
    for(int i = 0; i < str.length(); i++)
        if(isupper(str[i]))
            counter++;
    return counter; 
}

int main()
{
    ifstream fin("input.txt");
    if(fin.is_open())
    {
        int dictSize;
        fin >> dictSize;
        unordered_map<string, unordered_set<string>> dictionary;
        string word;
        int mistakesCount = 0;
        for(int i = 0; i < dictSize; i++)
        {
            fin >> word;
            dictionary[toLower(word)].insert(word);
        }
        while(fin >> word)
        {
            switch (StressCount(word))
            {
            case 1:
            {
                if(!dictSize)
                    break;
                auto line = dictionary.find(toLower(word));
                if(line != dictionary.end() && (*line).second.find(word) == (*line).second.end())
                    mistakesCount++;
                break;
            }
            default:
                mistakesCount++;
                break;
            }
        }
        cout << mistakesCount;
    }
}
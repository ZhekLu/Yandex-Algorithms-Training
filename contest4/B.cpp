#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    if(fin.is_open())
    {
        unordered_map<string, int> bookMap;
        string word;
        while(fin >> word)
        {
            cout << bookMap[word] << " ";
            bookMap[word]++;
        }
        fin.close();
    }
}
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    if(fin.is_open())
    {
        unordered_map<string, int> bookMap;
        set<string> commonWords;
        string word;
        int maxCount = 0;
        while(fin >> word)
        {
            int currCount = ++bookMap[word];
            if(currCount > maxCount)
            {
                commonWords.clear();
                maxCount = currCount;
                commonWords.insert(word);
            }
            else if (currCount == maxCount)
            {
                commonWords.insert(word);
            }
        }
        cout << *commonWords.begin();
    }
}
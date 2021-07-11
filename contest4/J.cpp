#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void toLower(char* str)
{
    for(int i = 0; str[i] != '\0'; i++)
        if(isupper(str[i]))
            str[i] = tolower(str[i]);
}

void toLower(string& str)
{
    for(int i = 0; i < str.length(); i++)
        if(isupper(str[i]))
            str[i] = tolower(str[i]);
}

bool StartsWithDigit(const char* w)
{
    if(w[0] >= '0' && w[0] <= '9')
        return true;
    return false;
}

int main()
{
    fstream fin("input.txt");
    if(fin.is_open())
    {
        bool isSensitive, canStartWithNum;
        int n, maxWordCount = 0;
        fin >> n;
        unordered_set<string> keyWords(n), commonWords;
        unordered_map<string, pair<int, int>> progText; //<word, <pos, count>>
        string line;
        char cline[128];
        fin >> line; 
        isSensitive = line == "yes";
        fin >> line;
        canStartWithNum = line == "yes";
        for(int i = 0; i < n; i++)
        {
            fin >> line;
            if(!isSensitive)
                toLower(line);
            keyWords.insert(line);
        }
        unsigned pos = 0;
        while(fin.getline(cline, 128))
        {
            char* word = strtok(cline, " ,.;\"}{)(+=-%");
            while(word)
            {
                if(!isSensitive)
                    toLower(word);
                if(keyWords.find(word) != keyWords.end() || (StartsWithDigit(word) && !canStartWithNum))
                {
                    word = strtok(NULL, " ,.;\"}{)(+=-%&");
                    continue;
                }
                auto lib = progText.find(word);
                int currCount = 1; 
                if(lib != progText.end())
                   currCount = ++(((*lib).second).second);
                
                else  
                    progText.insert(pair(word, pair(pos, 1)));
                
                if(currCount > maxWordCount)
                {
                    commonWords.clear();
                    commonWords.insert(word);
                    maxWordCount = currCount;
                }
                else if(currCount == maxWordCount)
                {
                    commonWords.insert(word);
                }
                pos++;
                word = strtok(NULL, " ,.;\"}{)(+=-%");
            }
        }
        fin.close();
        unsigned earliestPos = UINT32_MAX;
        auto answer = commonWords.begin();
        for(auto it = answer; it != commonWords.end(); ++it)
        {
            if(progText[*it].first < earliestPos)
            {
                earliestPos = progText[*it].first;
                answer = it;
            }
        }
        cout << *answer;
    }
}
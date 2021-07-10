#include <iostream>
#include <string>
#include <unordered_map>
using namespace std; 

bool Consist(unordered_map<char, int> word, const string& str)
{
    for(int i = 0; i < str.length(); i++)
    {   
        int q = --word[str[i]];
        if(q < 0)
            return false; 
    }
    return true;
}

int main()
{
    int g, sLen, intersection = 0;
    unordered_map<char, int> W;
    string S;
    cin >> g >> sLen;
    for(int i = 0; i < g; i++)
    {
        char symb; 
        cin >> symb;
        W[symb]++;
    }
    cin >> S; 

    for(int i = 0; i <= sLen - g; i++)
    {
        string potentialW = S.substr(i, g);
        if(Consist(W, potentialW))
            intersection++;
    }
    cout << intersection;
}
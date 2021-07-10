#include <iostream>
#include <string>
#include <unordered_map>
using namespace std; 

int CheckMatch(const unordered_map<char, int>& word, const unordered_map<char, int>& str)
{
    int counter = 0;
    for(auto&[sym, q] : word)
        if(str.find(sym) != str.end() && str.at(sym) == q)
            counter++;
    return counter;
}

bool isInfluences(const unordered_map<char, int>& word, const unordered_map<char, int>& str, const char& symb)
{
    if(word.find(symb) != word.end() && str.find(symb) != str.end() && word.at(symb) == str.at(symb))
        return true;
    return false;
}

int CheckSymbol(const unordered_map<char, int>& word, unordered_map<char, int>& str, const char& symb, int mode)
{
    int res = 0;
    if(isInfluences(word, str, symb))
        res--;
    str[symb] += mode;
    if(isInfluences(word, str, symb))
        res++;
    return res;
}

int main()
{
    int g, sLen, intersection = 0;
    unordered_map<char, int> W, Str;
    string S;
    cin >> g >> sLen;
    if(g > sLen)
    {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < g; i++)
    {
        char symb; 
        cin >> symb;
        W[symb]++;
    }
    cin >> S; 

    int sameLetters = 0, lettersCount = W.size();
    for(int i = 0; i < g; i++)
        Str[S[i]]++;
    sameLetters = CheckMatch(W, Str);
    if(sameLetters == lettersCount)
        intersection++;
    
    for(int i = 1; i <= sLen - g; i++)
    {
        //delete the last sym
        sameLetters += CheckSymbol(W, Str, S[i - 1], -1);
        
        //add a new sym
        sameLetters += CheckSymbol(W, Str, S[i + g - 1], 1);

        if(sameLetters == lettersCount)
            intersection++;
    }
    cout << intersection;
}
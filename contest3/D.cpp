#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
using namespace std; 

int main()
{
    ifstream fin("input.txt");
    if(fin.is_open())
    {
        string word; 
        unordered_set<string> book;
        while(fin >> word)
            if(book.find(word) == book.end())
                book.insert(word);

        cout << book.size();
    }
}
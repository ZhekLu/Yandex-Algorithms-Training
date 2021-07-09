#include <unordered_map>
#include <iostream>
#include <string>
using namespace std; 

int main()
{
    int N;
    string first, second;
    unordered_map<string, string> postord, preord;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> first >> second; 
        postord[first] = second;
        preord[second] = first; 
    }
    cin >> first;
    if(postord.find(first) != postord.end())
        cout << postord[first];
    else if(preord.find(first) != preord.end())
        cout << preord[first];
}
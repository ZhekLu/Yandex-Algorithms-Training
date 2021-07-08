#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    string first, second; 
    int answer = 0;
    unordered_set<string> bases; 

    cin >> first >> second;
    for(int i = 0; i < second.length() - 1; i++)
        bases.insert(second.substr(i, 2));
    for(int i = 0; i < first.length() - 1; i++)
        if(bases.find(first.substr(i, 2)) != bases.end())
            answer++;
    
    cout << answer; 
}

// count both entries
// int main()
// {
//     string first, second; 
//     int answer = 0; 
//     unordered_map<string, int> bases;

//     cin >> first; 
//     cin >> second; 
//     for(int i = 0; i < second.length() - 1; i++)
//     {
//         bases[second.substr(i, 2)]++; 
//     } 

//     for(int i = 0; i < first.length() - 1; i++)
//     {
//         string base = first.substr(i, 2);
//         if(bases.find(base) != bases.end())
//             answer += bases[base];
//     }
//     cout << answer; 
// }
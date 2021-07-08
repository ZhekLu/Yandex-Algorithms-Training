#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std; 

int main()
{
    unordered_map<string, unsigned short> table;
    unordered_set<string> languages;
    unsigned short N;
    unordered_set<string> all_know;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int M;
        cin >> M;
        for(int j = 0; j < M; j++)
        {
            string temp;
            cin >> temp;
            
            table[temp]++;
            if(table[temp] == N)
                all_know.insert(temp);
            else
                languages.insert(temp);
        }
    }
    
    cout << all_know.size() << endl;
    for(auto& l : all_know)
        cout << l << endl;
    cout << languages.size() << endl;
    for(auto& l : languages)
        cout << l << endl;
}
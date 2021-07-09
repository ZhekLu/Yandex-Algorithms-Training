#include <unordered_map>
#include <iostream>
#include <string>
using namespace std; 

//with anordered_map
int main()
{
    int quantity;
    cin >> quantity;
    unordered_map<int, int> keys(quantity);
    for(int i = 1; i <= quantity; i++)
    {
        int maxQ;
        cin >> maxQ;
        keys[i] = maxQ;
    }

    int pushQ;
    cin >> pushQ;
    for(int i = 0; i < pushQ; i++)
    {
        int key;
        cin >> key;
        keys[key]--;
    }

    for(int k = 1; k <= quantity; k++)
    {
        if(keys[k] < 0)
            cout << "YES\n";
        else  
            cout << "NO\n";
    }
}
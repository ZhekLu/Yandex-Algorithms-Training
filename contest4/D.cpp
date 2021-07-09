#include <iostream>
using namespace std; 

int main()
{
    short n;
    cin >> n;
    int* keys = new int [n + 1];
    for(int i = 1; i <= n; i++)
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

    for(int i = 1; i <= n; i++)
    {
        if(keys[i] < 0)
            cout << "YES\n";
        else  
            cout << "NO\n";
    }
}

/*
//with std::map
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
*/
/*
int main()
{
    int quantity;
    cin >> quantity;
    map<int, int> keys;
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

    for(auto& key : keys)
    {
        if(key.second < 0)
            cout << "YES\n";
        else  
            cout << "NO\n";
    }
}
*/
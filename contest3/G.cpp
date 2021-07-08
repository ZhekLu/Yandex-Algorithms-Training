#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int N;
    cin >> N;
    unordered_set<int> answ; 
    for(int i = 0; i < N; i++)
    {
        int bef, aft;
        cin >> bef >> aft; 
        if(bef >= 0 && aft >= 0 && bef + aft + 1 == N)
            answ.insert(bef);
    }
    cout << answ.size(); 
}
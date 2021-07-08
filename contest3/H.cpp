#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int N;
    cin >> N;
    unordered_set<int> res;
    for(int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        res.insert(x);
    }
    cout << res.size();
}
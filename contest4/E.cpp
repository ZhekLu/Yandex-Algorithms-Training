#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<unsigned, unsigned> bricks; //[w, h]
    unsigned n; 
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int w, h;
        cin >> w >> h;
        if(h > bricks[w])
            bricks[w] = h;
    }

    int maxH = 0;
    for(auto&[w, h] : bricks)
    {
        maxH += h;
    }
    cout << maxH;
}
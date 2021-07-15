#include <iostream>
using namespace std;

inline bool checkSize(long long protecSize, const long long* params)
{
    return (params[3] / (params[1] + 2 * protecSize)) * (params[4] / (params[2] + 2 * protecSize)) >= params[0];
}

long long RBinSearch(long long l, long long r, bool(*check)(long long, const long long*),const long long* checkParams)
{
    long long m;
    while(l < r)
    {
        m = (l + r + 1) / 2;
        if(check(m, checkParams))
            l = m;
        else  
            r = m - 1;
    }
    return l;
}

int main()
{
    // n, a, b, w, h |: a, b - segment sizes | w, h - field sizes;
    long long dimentions[5];
    for(int i = 0; i < 5; i++)
        cin >> dimentions[i]; 
    // a > | < b 
    long long horLocation =  RBinSearch(0, dimentions[3] - dimentions[1], checkSize, dimentions);
    // a < | > b
    swap(dimentions[1], dimentions[2]);
    long long verLocation =  RBinSearch(0, dimentions[3] - dimentions[1], checkSize, dimentions);

    cout << (horLocation > verLocation ? horLocation : verLocation);
    return 0;
}
#include <iostream>
using namespace std;

inline bool checkPathWidth(long long pathWidth, const long long* params)
{
    return params[0] >= 2 * pathWidth && 
    2 * pathWidth * (params[0] - 2 * pathWidth + params[1]) <= (params[2] < params[0] * params[1] ? params[2] : params[0] * params[1]);
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
    // n - width, m - height, t - tile number;
    long long dimentions[3];
    for(int i = 0; i < 3; i++)
        cin >> dimentions[i]; 

    cout << RBinSearch(0, (dimentions[1] < dimentions[0] ? dimentions[1] : dimentions[0]) / 2, checkPathWidth, dimentions);
    return 0;
}
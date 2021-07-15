#include <iostream>
using namespace std;

inline bool checkSize(long long sideLen, const unsigned* params)
{
    return (sideLen / params[0]) * (sideLen / params[1]) >= params[2];
}

long long LBinSearch(long long l, long long r, bool(*check)(long long, const unsigned*),const unsigned* checkParams)
{
    long long m;
    while(l < r)
    {
        m = (l + r) / 2;
        if(check(m, checkParams))
            r = m;
        else  
            l = m + 1;
    }
    return l;
}

int main()
{
    unsigned input[3]; //w, h, n;
    for(int i = 0; i < 3; i++)
        cin >> input[i];
    cout << LBinSearch(0, (long long)(input[2] + 2) / 2 * (input[0] > input[1] ? input[0] : input[1]), checkSize, input);
}
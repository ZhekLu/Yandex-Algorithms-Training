#include <iostream>
using namespace std;

bool checkSize(unsigned sideLen, const unsigned* params)
{
    return (sideLen / params[0]) * (sideLen / params[1]) >= params[2];
}

unsigned LBinSearch(unsigned l, unsigned r, bool(*check)(unsigned, const unsigned*),const unsigned* checkParams)
{
    unsigned m;
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
    cout << LBinSearch(0, input[2] * (input[0] > input[1] ? input[0] : input[1]), checkSize, input);
}
#include <iostream>
using namespace std;

inline bool checkCopies(unsigned seconds, const unsigned* params)
{
    return seconds / params[1] + seconds / params[2] >= params[0]; 
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
    unsigned input[3]; //N, x_speed, y_speed;
    for(int i = 0; i < 3; i++)
        cin >> input[i];
    cout << LBinSearch(0, input[0]-- * (input[1] > input[2] ? input[1] : input[2]) / 2, checkCopies, input)
     + (input[1] < input[2] ? input[1] : input[2]);
}
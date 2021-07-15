#include <iostream>
using namespace std;

inline bool checkResMark(long long numberOfFives, const long long* params)
{
    unsigned long long resMark = 5 * numberOfFives; // + 4 * params[0] + 3 * params[1] + 2 * params[2]
    unsigned long long marksNum = numberOfFives;
    for(int i = 0; i < 3; i++)
    {
        resMark += (i + 2) * params[i];
        marksNum += params[i];
    }

    return resMark / marksNum + (resMark % marksNum >= (marksNum + 1) / 2 ? 1 : 0) >= params[3];
}

long long LBinSearch(long long l, long long r, bool(*check)(long long, const long long*),const long long* checkParams)
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
    long long input[4]; //a - 2, b - 3, c - 4, d - min desired mark; 
    for(int i = 0; i < 3; i++)
        cin >> input[i];
    input[3] = 4;
    cout << LBinSearch(0, input[0] + input[1] + input[2], checkResMark, input);
}
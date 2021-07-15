#include <iostream>
using namespace std;

inline bool checkLength(unsigned wireLen, const unsigned* params)
{
    unsigned resultNum = 0;
    for(int i = 2; i < params[0] + 2; i++)
        resultNum += params[i] / wireLen;
    return resultNum >= params[1];
}

long long RBinSearch(unsigned l, unsigned r, bool(*check)(unsigned, const unsigned*),const unsigned* checkParams)
{
    unsigned m;
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
    unsigned N, K;
    cin >> N >> K;
    unsigned* dimentions = new unsigned[N + 2]; // N - lines number, K - required lines number, L1 ... LN
    dimentions[0] = N; dimentions[1] = K;  
    long long sum = 0;
    for(int i = 2; i < dimentions[0] + 2; i++)
    {
        cin >> dimentions[i]; 
        sum += dimentions[i];
    }
    cout << sum << endl << endl;
    cout << RBinSearch(0, sum / K, checkLength, dimentions);
    
    delete[] dimentions;
    return 0;
}
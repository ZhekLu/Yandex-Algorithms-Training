#include <iostream>
#include <unordered_map>
using namespace std; 

int main()
{
    unsigned symbolNum, maxDuplicateNum;
    cin >> symbolNum >> maxDuplicateNum;

    char* str = new char[symbolNum + 1]{' '};
    unordered_map<char, int> maxSubStr;

    int maxSubLen = INT32_MIN, bestL = 0;
    int l, r;
    for(l = 0, r = 0; r < symbolNum; r++)
    {
        char symbol;
        cin >> symbol;
        str[r] = symbol;
        int count = ++maxSubStr[symbol];
        if(count > maxDuplicateNum)
        {
            if(r - l > maxSubLen)
            {
                maxSubLen = r - l;
                bestL = l + 1;
            }
            while(maxSubStr[symbol] > maxDuplicateNum && l <= r)
                maxSubStr[str[l++]]--;
        }
    } 
    if(r - l > maxSubLen)
    {
        maxSubLen = r - l;
        bestL = l + 1;
    }
    cout << maxSubLen << " " << bestL;
    delete[] str;
}
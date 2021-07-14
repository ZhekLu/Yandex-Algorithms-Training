#include <iostream>
#include <string>
#include <fstream>
using namespace std;

unsigned long MaxNumOfUsefulOperations(const string& str, int memorySize)
{
    unsigned long answer = 0;
    for(int i = memorySize, lastLen = 0; i < str.length(); i++)
    {
        if(str[i] == str[i - memorySize])
            lastLen++;
        else 
            lastLen = 0;
        answer += lastLen;
    }
    return answer;
}

int main()
{
    ifstream fin("input.txt");
    if(fin.is_open())
    {
        int memorySize;
        fin >> memorySize;
        string operations;
        fin >> operations;
        
        cout << MaxNumOfUsefulOperations(operations, memorySize);
        fin.close();
    }
}
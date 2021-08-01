#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

bool isSatisfy(const pair<short, short>* secureList, short size, short beginOfCheck, short endOfCheck)
{
    if(secureList[0].first != beginOfCheck || secureList[size - 1].second != endOfCheck)
        return false;
    
    short lastLeaveTime = beginOfCheck;
    for(short i = 1; i < size; i++)
    {
        if(secureList[i].first <= lastLeaveTime)
            return false;
        
        lastLeaveTime = secureList[i - 1].second;

        if(secureList[i].first > lastLeaveTime || secureList[i].second <= lastLeaveTime)
            return false; 
    }

    return true;
}

int main()
{
    short testsNum;
    cin >> testsNum;

    ofstream fout("output.txt");
    while(testsNum--)
    {
        short securityNum;
        cin >> securityNum;
        pair<short, short>* schedule = new pair<short, short>[securityNum];
        for(int i = 0; i < securityNum; i++)
            cin >> schedule[i].first >> schedule[i].second;
        sort(schedule, schedule + securityNum);

        fout << (isSatisfy(schedule, securityNum, 0, 10000) ? "Accepted" : "Wrong Answer") << endl;

        delete[] schedule;
    }
    fout.close();
}
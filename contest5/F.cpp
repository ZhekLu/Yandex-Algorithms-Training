#include <iostream>
#include <map>
using namespace std; 

int main()
{
    unsigned short roomsNum, conditionNum;
    cin >> roomsNum;
    map<unsigned short, unsigned short> powerTable; // key - power|value - number
    map<unsigned short, unsigned short> conditionTable; // key - cost|value - power
    for(int i = 0; i < roomsNum; i++)
    {
        short power; 
        cin >> power; 
        powerTable[power]++;
    }
    cin >> conditionNum;
    for(int i = 0; i < conditionNum; i++)
    {
        short power, cost;
        cin >> power >> cost;
        if(conditionTable[cost] < power)
            conditionTable[cost] = power; 
    }

    unsigned minCostSum = 0;
    for(auto power = powerTable.begin(), cond = conditionTable.begin(); power != powerTable.end() && cond != conditionTable.end(); power++)
    {
        while(power->first > cond->second)
            cond++;
        minCostSum += cond->first * power->second; 
    }
    cout << minCostSum;
}
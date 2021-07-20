#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>
#include <algorithm>
using namespace std;

enum Events
{
    CUSTOMER_IN, CUSTOMER_OUT
};

int main()
{
    int customersNum, adLen = 5;
    cin >> customersNum;
    vector<tuple<int, int, int>> custEvents; //time, type. index
    for(int i = 0, b, e; i < customersNum; i++)
    {
        cin >> b >> e;
        if(e - b >= adLen)
        {
            custEvents.push_back(make_tuple(b, CUSTOMER_IN, i));
            custEvents.push_back(make_tuple(e - adLen, CUSTOMER_OUT, i));
        }
    }
    sort(custEvents.begin(), custEvents.end());
   
     
    unordered_set<int> viewedAd;
    int maxNum = -1, firstNum = 0, secondNum = 0, bestFTime = 0, bestStime = -1;
    for(int i = 0; i < custEvents.size(); i++)
    {
        auto&[time1, type1, index1] = custEvents[i];
        if(type1 == CUSTOMER_IN)
        {
            firstNum++;
            viewedAd.insert(index1);
            if(maxNum < firstNum)
            {
                maxNum = firstNum;
                bestFTime = time1;
            }
        }
        for(int j = i + 1; j < custEvents.size(); j++)
        {
            auto&[time2, type2, index2] = custEvents[j];
            if(viewedAd.find(index2) == viewedAd.end())
            {
                if(type2 == CUSTOMER_IN)
                    secondNum++;

                if(time2 - time1 >= adLen && secondNum + firstNum > maxNum)
                {
                    maxNum = secondNum + firstNum;
                    bestFTime = time1;
                    bestStime = time2;
                }

                if(type2 == CUSTOMER_OUT)  
                    secondNum--;
            }
        }
        if(type1 == CUSTOMER_OUT)
        {
            viewedAd.erase(index1);
            firstNum--;
        }
    }
    if(bestStime == -1)
        bestStime = bestFTime + adLen;
    cout << maxNum << " " << bestFTime << " " << bestStime;

}
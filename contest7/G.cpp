#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
    int balloonNum, assistantNum;
    cin >> balloonNum >> assistantNum;
    vector<tuple<int, int, int, int>> assistants; // T, Y, Z, index
    for(int i = 0, T, Z, Y; i < assistantNum; i++)
    {
        cin >> T >> Z >> Y; 
        assistants.push_back(make_tuple(T, Y, Z, i));
    }


    vector<int> assistantBalloonNum(assistantNum);
    vector<int> lastActivity(assistantNum);
    int  overalBalNum = 0, nextTime, nextIndex;
    while(overalBalNum < balloonNum)
    {
        nextTime = INT32_MAX;
        for(const auto&[balTime, breakTime, balNum, index] : assistants)
        {
            int nextiTime = lastActivity[index] + balTime; 
            if(assistantBalloonNum[index] && assistantBalloonNum[index] % balNum == 0)
                nextiTime += breakTime;
            if(nextiTime < nextTime)
            {
                nextTime = nextiTime;
                nextIndex = index;
            }
        }

        lastActivity[nextIndex] = nextTime;
        assistantBalloonNum[nextIndex]++;

        overalBalNum++;
    }
    cout << nextTime << endl;
    for(auto& n : assistantBalloonNum)
        cout << n << " ";

}
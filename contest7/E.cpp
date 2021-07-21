#include <iostream>
#include <set>
using namespace std;

enum Events
{
    TIME_CLOSE = -1, TIME_OPEN = 1,
};

int main()
{
    int checkoutNum, openNum = 0;
    cin >> checkoutNum;
    multiset<pair<int, int>> events;
    for(int i = 0, h, m, b, e; i < checkoutNum; i++)
    {
        cin >> h >> m;
        b = h * 60 + m;
        cin >> h >> m;
        e = h * 60 + m;
        
        events.insert(make_pair(b, TIME_OPEN));
        events.insert(make_pair(e, TIME_CLOSE));
        
        if(b >= e)
            openNum++;
    }

    int startAllOpenTime = 0, timeAllOpen = 0;
    for(auto&[time, type] : events)
    {
        if(openNum == checkoutNum)
            timeAllOpen += time - startAllOpenTime;

        openNum += type;

        if(openNum == checkoutNum)
            startAllOpenTime = time;
    }
    if(openNum == checkoutNum)
        timeAllOpen += 24 * 60 - startAllOpenTime;

    cout << timeAllOpen;
}
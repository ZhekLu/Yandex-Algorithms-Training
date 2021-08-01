#include <iostream>
#include <tuple>
#include <stdio.h>
#include <set>
using namespace std;

enum Events
{
    ARRIVAL = -1, DEPARTURE = 1
};

int main()
{
    int cityNum, tripNum;
    cin >> cityNum >> tripNum;
    multiset<tuple<int, int, int>> events; //time, type, index
    int nightBusNum = 0;
    for(int i = 0, city, h, m, arrivalTime, departureTime; i < tripNum; i++)
    {
        scanf("%d %d:%d", &city, &h, &m);
        departureTime = h * 60 + m;
        events.insert(make_tuple(departureTime, DEPARTURE, city));

        scanf("%d %d:%d", &city, &h, &m);
        arrivalTime = h * 60 + m;
        events.insert(make_tuple(arrivalTime, ARRIVAL, city));

        if(departureTime > arrivalTime)
            nightBusNum++;
    }

    int* balanceFactor = new int[cityNum + 1]{0};
    int* busCount = new int[cityNum + 1]{0};
    for(auto&[time, type, city] : events)
    {
        balanceFactor[city] -= type;

        if(type == ARRIVAL)
            busCount[city]++;
        else  
            if(busCount[city] > 0)
                busCount[city]--;
    }

    int answer = 0;
    for(int i = 1; i <= cityNum; i++)
    {
        if(balanceFactor[i])
        {
            answer = -1 - nightBusNum;
            break;
        }
        answer += busCount[i];
    }
    cout << answer + nightBusNum;
}
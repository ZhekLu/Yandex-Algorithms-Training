#include <iostream>
#include <set>
using namespace std;

enum Events : int
{
    SEGMENT_BEGIN = -1, SEGMENT_END = INT32_MAX
};

int* PointsEntryNum(const multiset<pair<int, int>>& events, int pointsNum)
{
    int* inclusions = new int[pointsNum];
    int activeSegmentsNum = 0;
    for(auto&[coordinate, type] : events)
    {
        if(type == SEGMENT_BEGIN)
            activeSegmentsNum++;
        else if (type == SEGMENT_END)
            activeSegmentsNum--;
        else  
            inclusions[type] = activeSegmentsNum;
    }
    return inclusions;
}  

int main()
{
    int segmentsNum, pointsNum; //n, m
    cin >> segmentsNum >> pointsNum;
    multiset<pair<int, int>> events;

    for(int i = 0; i < segmentsNum; i++)
    {
        int begin, end;
        cin >> begin >> end;
        if(begin > end)
            swap(begin, end);
        
        events.insert(make_pair(begin, SEGMENT_BEGIN));
        events.insert(make_pair(end, SEGMENT_END));
    }

    for(int i = 0; i < pointsNum; i++)
    {
        int point;
        cin >> point;
        events.insert(make_pair(point, i));
    }

    int* pointsInclusions = PointsEntryNum(events, pointsNum);
    for(int i = 0; i < pointsNum; i++)
        cout << pointsInclusions[i] << " ";

    delete[] pointsInclusions;
}
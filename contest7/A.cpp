#include <iostream>
#include <set>
using namespace std;

enum Events
{
    SEGMENT_BEGIN, SEGMENT_END
};

int UnsupervisedStudentsNum(int studentsNum, const multiset<pair<int, int>>& supervisedDesks)
{
    int activeSegmentsNum = 0, leftPos = -1;
    for(auto&[coordinate, event] : supervisedDesks)
    {
        if(event == SEGMENT_BEGIN)
        {
            if(!activeSegmentsNum)
                leftPos = coordinate;
            activeSegmentsNum++;
        }
        else  
        {
            activeSegmentsNum--;
            if(!activeSegmentsNum)
                studentsNum -= (coordinate - leftPos + 1);
        }
    }
    return studentsNum;
}

int main()
{
    int studentsNum, teachersNum; //N, M
    cin >> studentsNum >> teachersNum;
    multiset<pair<int, int>> supervised;
    for(int i = 0; i < teachersNum; i++)
    {
        int begin, end;
        cin >> begin >> end;
        supervised.insert(make_pair(begin, SEGMENT_BEGIN));
        supervised.insert(make_pair(end, SEGMENT_END));
    }

    int unsupervisedStNum = UnsupervisedStudentsNum(studentsNum, supervised);
    cout << unsupervisedStNum;
}
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

long long NumberOfIsoscelesTriangles(set<pair<int, int>>& points)
{
    unordered_map<long long, unsigned> length;
    set<pair<int, int>> wasInUse; //check if the points are on the same line
    long long answer = 0;
    for(auto&[x1, y1] : points)
    {
        for(auto&[x2, y2] : points)
        {
            int lenX = x1 - x2;
            int lenY = y1 - y2;
            long long len = (long long)lenX * lenX + (long long)lenY * lenY;
            if(wasInUse.find(make_pair(lenX, lenY)) != wasInUse.end())
                answer--;
            else  
                wasInUse.insert(make_pair(-lenX, -lenY));
            length[len]++;
        }
        for(auto&[len, num] : length)
            answer += ((num - 1) * num) / 2;

        wasInUse.clear();
        length.clear();
    }
    return answer;
}

int main()
{
    unsigned pointsNum;
    cin >> pointsNum;
    set<pair<int, int>> points;
    for(int i = 0; i < pointsNum; i++)
    {
        int x, y;
        cin >> x >> y;
        points.insert(pair<int, int>(x, y));
    }
    
    cout << NumberOfIsoscelesTriangles(points);
}
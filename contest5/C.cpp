#include <iostream>
using namespace std;

int* MakePositivePrefix(const int* from, int size)
{
    int* prefix = new int[size + 1]{0};
    for(int i = 1; i <= size; i++)
        if (from[i - 1] > 0)
            prefix[i] = prefix[i - 1] + from[i - 1];
        else  
            prefix[i] = prefix[i - 1];
        
    return prefix;
}

int* MakeNegativePrefix(const int* from, int size)
{
    int* prefix = new int[size + 1]{0};
    for(int i = 1; i <= size; i++)
        if (from[i - 1] < 0)
            prefix[i] = prefix[i - 1] + from[i - 1];
        else  
            prefix[i] = prefix[i - 1];
        
    return prefix;
}

int* MakeHeightScale(const int* from, int size)
{
    int* heights = new int[size]{0};
    for(int i = 1; i < size; i++)
        heights[i] = from[i] - from[i - 1];

    return heights;
}

int main()
{
    int pointsNum, trailNum;
    cin >> pointsNum;
    int* points = new int[pointsNum];
    for(int i = 0; i < pointsNum; i++)
        cin >> points[i] >> points[i]; // just skip x-coo
    
    int* heightScale = MakeHeightScale(points, pointsNum);
    int* posPrefixHeight = MakePositivePrefix(heightScale, pointsNum);
    int* negPrefixHeight = MakeNegativePrefix(heightScale, pointsNum);

    cin >> trailNum;
    int* answer = new int[trailNum]; 
    for(int i = 0; i < trailNum; i++)
    {
        int firstP, secondP;
        cin >> firstP >> secondP;
        if(firstP < secondP)
            answer[i] = posPrefixHeight[secondP] - posPrefixHeight[firstP];
        else  
            answer[i] = negPrefixHeight[secondP] - negPrefixHeight[firstP];
        
    }

    for(int i = 0; i < trailNum; i++)
        cout << answer[i] << endl;

    delete[] heightScale, posPrefixHeight, negPrefixHeight, answer;
}
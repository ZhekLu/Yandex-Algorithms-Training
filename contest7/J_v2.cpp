#include <iostream>
#include <set>
#include <tuple>
using namespace std;

enum Events
{
    BLOCK_END = -1, BLOCK_START = 1
};

int main()
{
    int blockNum, W, L;
    cin >> blockNum >> W >> L;
    set<tuple<int, Events, int, int>> events; //z, type, area, index
    pair<int, int>* blocks = new pair<int, int>[blockNum + 1];
    for(int i = 1, x1, y1, z1, x2, y2, z2, area; i <= blockNum; i++)
    {
       cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
       area = (x2 - x1) * (y2 - y1);
       events.insert(make_tuple(z1, BLOCK_START, area, i));
       events.insert(make_tuple(z2, BLOCK_END, area, i));

       blocks[i].first = z1; blocks[i].second = z2;
    }

    int complexArea = W * L, currArea = 0;
    int minBlocksNum = INT32_MAX, currBlocksNum = 0, minZ;
    for(auto&[z, type, area, index] : events)
    {
        currBlocksNum += type;
        currArea += type * area;

        if(currArea == complexArea && currBlocksNum < minBlocksNum)
        {
            minBlocksNum = currBlocksNum;
            minZ = z;
        }
    }

    if(minBlocksNum > blockNum)
    {
        cout << "NO";
    }
    else 
    {
        cout << "YES" << endl << minBlocksNum << endl;
        for(int i = 1; i <= blockNum; i++)
        {
            if(blocks[i].first <= minZ && blocks[i].second > minZ)
                cout << i << endl;
        }
    }
}
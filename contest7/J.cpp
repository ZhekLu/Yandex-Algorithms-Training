#include <iostream>
#include <set>
#include <tuple>
#include <unordered_set>
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
    for(int i = 1, x1, y1, z1, x2, y2, z2, area; i <= blockNum; i++)
    {
       cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
       area = (x2 - x1) * (y2 - y1);
       events.insert(make_tuple(z1, BLOCK_START, area, i));
       events.insert(make_tuple(z2, BLOCK_END, area, i));
    }

    int complexArea = W * L;
    int minBlocksNum = INT32_MAX, currBlocksNum = 0, currArea = 0;
    for(auto&[z, type, area, index] : events)
    {
        currBlocksNum += type;
        currArea += type * area;

        if(currArea == complexArea && currBlocksNum < minBlocksNum)
            minBlocksNum = currBlocksNum;
    }

    if(minBlocksNum > blockNum)
    {
        cout << "NO";
    }
    else 
    {
        cout << "YES" << endl << minBlocksNum << endl;
        unordered_set<int> nowUsed;
        for(auto&[z, type, area, index] : events)
        {
            currBlocksNum += type;
            currArea += type * area;

            if(type == BLOCK_START)
            {
                nowUsed.insert(index);
                if(currArea == complexArea && currBlocksNum == minBlocksNum)
                    break;
            }
            else  
            {
                nowUsed.erase(index);
            }
        }
        for(auto& ind : nowUsed)
            cout << ind << endl;
    }
}
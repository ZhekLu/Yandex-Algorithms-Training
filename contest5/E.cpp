#include <iostream>
using namespace std; 

pair<unsigned, unsigned> FindMinSegment(const int* order, unsigned size, unsigned uniqueElementsNum)
{
    int* elements = new int[uniqueElementsNum + 1]{0};

    unsigned currElementsNum = 0, bestL = 1, bestR = size; 
    for(unsigned l = 0, r = 0; r < size;)
    {
        int currKind = order[r];
        if(!elements[currKind]++)
            currElementsNum++;
        r++;
        if(currElementsNum == uniqueElementsNum)
        {
            while(elements[currKind])
            {
                currKind = order[l];
                elements[currKind]--;
                l++;
            }
            currElementsNum--;
            if(r - l < bestR - bestL)
            {
                bestR = r; bestL = l;
            }
        }
    }
    delete[] elements;
    return make_pair(bestL, bestR);
}

int main()
{
    unsigned treesNum, kindsNum; 
    cin >> treesNum >> kindsNum;
    int* trees = new int[treesNum];
    for(unsigned i = 0; i < treesNum; i++)
        cin >> trees[i];
    pair<unsigned, unsigned> answer = FindMinSegment(trees, treesNum, kindsNum);
    cout << answer.first << " " << answer.second;
    delete[] trees;
}
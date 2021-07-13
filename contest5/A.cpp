#include <iostream>
#include <tuple>
using namespace std;

tuple <unsigned, unsigned, unsigned> MinDif(int* frArr, unsigned frSize, int* secArr, unsigned secSize)
{
    unsigned frIndex = 0, secIndex = 0;
    unsigned minDif = UINT32_MAX;
    for(int i = 0, j = 0; i < frSize && j < secSize; (frArr[i] < secArr[j])? i++ : j++)
    {
        if(frArr[i] == secArr[j])
            return make_tuple(0, i, j);
        if(abs(frArr[i] - secArr[j]) < minDif)
        {
            minDif = abs(frArr[i] - secArr[j]);
            frIndex = i; secIndex = j;
        }
    }
    return make_tuple(minDif, frIndex, secIndex);
}

int main()
{
    unsigned shirtsQ, pantsQ;
    cin >> shirtsQ;
    int* shirts = new int[shirtsQ];
    for(int i = 0; i < shirtsQ; i++)
        cin >> shirts[i]; 
    cin >> pantsQ;
    int* pants = new int[pantsQ];
    for(int i = 0; i < pantsQ; i++)
        cin >> pants[i]; 

    auto[minDif, shirtsInd, pantsInd] = MinDif(shirts, shirtsQ, pants, pantsQ);
    cout << shirts[shirtsInd] << " " << pants[pantsInd];
    delete[] shirts, pants;
}
#include <iostream>
using namespace std;

int* MakePrefix(const int* from, int size)
{
    int* prefix = new int[size + 1]{0};
    for(int i = 1; i <= size; i++)
        prefix[i] = prefix[i - 1] + from[i - 1];
    return prefix;
}

int main()
{
    int N, K; 
    cin >> N >> K;
    int* carNums = new int[N];
    for(int i = 0; i < N; i++)
        cin >> carNums[i]; 

    int* prefixNums = MakePrefix(carNums, N);
    int sum, sumQ = 0;
    for(int l = 0, r = 1; r <= N && l < N;)
    {
        sum = prefixNums[r] - prefixNums[l];
        if(sum < K)
            r++;
        else if (sum > K)
            l++;
        else 
        {
            l++; r++; sumQ++;
        }
    } 
    cout << sumQ;
}
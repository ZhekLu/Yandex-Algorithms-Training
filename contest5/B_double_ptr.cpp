#include <iostream>
using namespace std; 

int SumOccur(const int* arr, int size, int requiredSum)
{
    int answer = 0, sum = 0;
    for(int l = 0, r = 0; r < size; r++)
    {
        sum += arr[r];
        while(sum > requiredSum && l < r)
        {
            sum -=  arr[l];
            l++;
        }
        if(sum == requiredSum)
            answer++;
    }
    return answer;
}

int main()
{
    int N, K;
    cin >> N >> K;
    int* carNums = new int[N];
    for(int i = 0; i < N; i++)
        cin >> carNums[i];

    cout << SumOccur(carNums, N, K);
    delete[] carNums;
}
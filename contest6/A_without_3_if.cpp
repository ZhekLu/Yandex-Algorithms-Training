#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(const int* array, int size, int value)
{
    int l = 0, r = size, m;
    while(l < r)
    {
        m = (r + l) / 2;
        if(array[m] >= value)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main()
{
    unsigned N, K;
    cin >> N >> K;
    int* arr = new int[N];
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    for(int i = 0; i < K; i++)
    {
        int val;
        cin >> val;
        int index = BinarySearch(arr, N, val);
        cout << ( index >= 0 && index < N && arr[index] == val ? "YES" : "NO") << endl;
    }
    delete[] arr; 
}
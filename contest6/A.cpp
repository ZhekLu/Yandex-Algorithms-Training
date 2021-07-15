#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(const int* array, int size, int value)
{
    int l = 0, r = size, m;
    while(l < r)
    {
        m = (r + l) / 2;
        if(array[m] > value)
            r = m;
        else if(array[m] < value)
            l = m + 1;
        else  
            return m;
    }
    return -1;
}

int main()
{
    unsigned N, K;
    cin >> N >> K;
    int* arr = new int[N];
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    // sort(arr, arr + N); 
    for(int i = 0; i < K; i++)
    {
        int val;
        cin >> val;
        cout << (BinarySearch(arr, N, val) != -1 ? "YES" : "NO") << endl;
    }
    delete[] arr; 
}
#include <iostream>
using namespace std;

int NearestValue(const int* arr, int size, int val)
{
    int l = 0, r = size, m;
    while(l < r)
    {
        m = (l + r) / 2;
        if(arr[m] > val)
            r = m;
        else if (arr[m] < val)
            l = m + 1;
        else  
            return val;
    }
    if(l == 0 || l != size && abs(arr[l] - val) < abs(arr[l - 1] - val))
        return arr[l];
    return arr[l - 1];
}

int main()
{
    unsigned N, K;
    cin >> N >> K;
    int* values = new int[N];
    for(int i = 0; i < N; i++)
        cin >> values[i];

    for(int i = 0; i < K; i++)
    {
        int num;
        cin >> num;
        cout << NearestValue(values, N, num) << endl;
    }
    
    delete[] values;
    return 0;
}
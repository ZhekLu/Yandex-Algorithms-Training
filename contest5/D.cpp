#include <iostream>
using namespace std;
 
long long FindPairsAtDist(const unsigned* arr, unsigned size, unsigned distance)
{
    long long counter = 0;
    for(int l = 0, r = 1; r < size;)
    {
        if(arr[r] - arr[l] > distance)
        {
            l++;
            counter += size - r; 
        }
        else  
        {
            r++;
        }
    }
    return counter;
}

int main()
{
    unsigned monumentNum, maxDist; 
    cin >> monumentNum >> maxDist;
    unsigned* monumentsCoo = new unsigned[monumentNum];
    for(int i = 0; i < monumentNum; i++)
    cin >> monumentsCoo[i];
    
    cout << FindPairsAtDist(monumentsCoo, monumentNum, maxDist);
    delete[] monumentsCoo;

}
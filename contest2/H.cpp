#include <iostream>
#include <vector>
#include <fstream>
using namespace std; 

void sortSide(vector<int>& arr, int lenSide);
int* maxMulti(vector<int>& arr);

int main()
{
    ifstream fin("input.txt");
    if(fin.is_open())
    {
        vector<int> sp;
        int num = 0;
        while(fin >> num)
            sp.push_back(num);
        fin.close();
        sortSide(sp, 3);
        int *ans = maxMulti(sp);
        for(int i = 0; i < 3; i++)
            cout << ans[i] << " ";
    }
}

void sortSide(vector<int>& arr, int lenSide)
{
    for(int i = 0; i < lenSide; i++)
    {
        for(int k = i, j = arr.size() - 1 - i; k < arr.size() - 1 - i && j > 0 + i; k++, j--)
        {
            int temp;
            if(arr[k] > arr[k + 1])
            {
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
            if(arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

int* maxMulti(vector<int>& arr)
{
    int* ans = new int[3]{0};
    if((long long)arr[arr.size() - 1] * (long long)arr[arr.size() - 2] * (long long)arr[arr.size() - 3] 
    > (long long)arr[0] * (long long)arr[1] * (long long)arr[arr.size() - 1])
    {    
        ans[0] = arr[arr.size() - 3];
        ans[1] = arr[arr.size() - 2];
        ans[2] = arr[arr.size() - 1];
    }
    else  
    {
        ans[0] = arr[0];
        ans[1] = arr[1];
        ans[2] = arr[arr.size() - 1];
    }
    return ans; 
}
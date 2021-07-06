#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    if(fin.is_open())
    {
        int num;
        vector<int> arr; 
        while(fin >> num)
        {
            if(find(arr.begin(), arr.end(), num) == arr.end())
                arr.push_back(num);
        }
        fin.close();
        cout << arr.size();
    }
}
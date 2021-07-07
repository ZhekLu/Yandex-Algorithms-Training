#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    if(fin.is_open())
    {
        int num;
        unordered_set<int> arr; 
        while(fin >> num)
            arr.insert(num); 
        
        fin.close();
        cout << arr.size();
    }
}
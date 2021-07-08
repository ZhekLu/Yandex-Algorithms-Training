#include <iostream>
#include <string>
#include <unordered_set>
using namespace std; 

bool Consist(int arr[3], int num)
{
    for(int i = 0; i < 3; i++)
        if(arr[i] == num)
            return true;
    return false; 
}

int main()
{
    int buttons[3];
    for(int i = 0; i < 3; i++)
        cin >> buttons[i];
    string num;
    cin >> num; 
    unordered_set<int> more; 
    for(int i = 0; i < num.size(); i++)
        if(!Consist(buttons, num[i] - '0') && more.find(num[i] - '0') == more.end())
            more.insert(num[i] - '0');
    cout << more.size();
}
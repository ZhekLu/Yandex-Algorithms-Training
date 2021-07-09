#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std; 

int main()
{
    ifstream fin("input.txt");
    if(fin.is_open())
    {
        map<string, map<string, long unsigned>> customerList;
        string name, product;
       	long unsigned quantity; 
        while(fin >> name >> product >> quantity)
            customerList[name][product] += quantity;
            
        for(auto& customer : customerList)
        {
            cout << customer.first << ":" << endl;
            for(auto& prodList : customer.second)
                cout << prodList.first << " " << prodList.second << endl;
        }
        
    }
}
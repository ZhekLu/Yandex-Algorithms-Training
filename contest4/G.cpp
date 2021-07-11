#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    if(fin.is_open())
    {
        unordered_map<string, long int> bank;
        string operation, name;
        long int sum;
        while(fin >> operation)
        {
            if(operation == "DEPOSIT")
            {
                fin >> name >> sum;
                bank[name] += sum;
            }
            else if (operation == "WITHDRAW")
            {
                fin >> name >> sum;
                bank[name] -= sum;
            }
            else if (operation == "BALANCE")
            {
                fin >> name;
                if(bank.find(name) != bank.end())
                    cout << bank[name] << endl;
                else  
                    cout << "ERROR" << endl;
            }
            else if (operation == "TRANSFER")
            {
                fin >> operation >> name >> sum;
                bank[operation] -= sum;
                bank[name] += sum;
            }
            else // if (operation == "INCOME")
            {
                fin >> sum;
                for(auto&[person, count] : bank)
                {
                    if(count > 0)
                    {
                        count *= (100 + sum);
                        count /= 100;
                    }
                }
            }
        }
        fin.close();
    }
}
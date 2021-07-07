#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    if(fin.is_open())
    {
        int num;
        unordered_set<int> first;
        set<int>second; 
        string reading;

        getline(fin, reading);
        stringstream fr(reading); 
        while(fr >> num)
            first.emplace(num);
        fr.clear();

        getline(fin, reading); 
        fin.close();
        fr.str(reading);
        while(fr >> num)
            if(first.find(num) != first.end())
                second.emplace(num);
        
        ofstream fout("output.txt");
        for(auto& i : second)
            fout << i << " "; 
        fout.close();
    }
}
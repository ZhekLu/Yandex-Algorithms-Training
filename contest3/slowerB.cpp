#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <deque>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    if(fin.is_open())
    {
        int num;
        set<int> first, second; 
        string reading;

        getline(fin, reading);
        stringstream fr(reading); 
        while(fr >> num)
            first.insert(num);
        fr.clear();

        getline(fin, reading); 
        fin.close();
        fr.str(reading);
        while(fr >> num)
            // if(first.find(num) != first.end())
                second.insert(num);
        
        deque<int> res; 
        set_intersection(first.begin(), first.end(), second.begin(), second.end(), inserter(res, res.begin()));

        ofstream fout("output.txt");
        for(auto& i : res)
            fout << i << " "; 
        fout.close();
    }
}
#include <iostream>
#include <tuple>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

enum Events : short
{
    ARRIVAL, DEPARTURE
};

int main()
{
    ofstream fout("output.txt");
    short testNum;
    cin >> testNum;
    while(testNum--)
    {
        short securityNum;
        vector<tuple<short, short, short>> events; //time, type, index
        cin >> securityNum;
        for(int i = 0, A, B; i < securityNum; i++)
        {
            cin >> A >> B;
            events.push_back(make_tuple(A, ARRIVAL, i));
            events.push_back(make_tuple(B, DEPARTURE, i));
        }
        sort(events.begin(), events.end());
        
        bool* wasAlone = new bool[securityNum]{0};
        bool wasNoOne = false; 
        unordered_set<short> workNow;
        short prevTime = 0;
        for(const auto&[time, type, index] : events)
        {
            if(time && workNow.empty())
            {
                wasNoOne = true;
                break;
            }
            if(workNow.size() == 1 && (time != prevTime))
                wasAlone[*(workNow.begin())] = true;

            if(type == ARRIVAL)
            {
                workNow.insert(index);
            }
            else  
                workNow.erase(index);
            
            prevTime = time;
        }

        if(wasNoOne || get<0>(events.back()) != 10000 || get<0>(events.front()) != 0)
        {
            fout << "Wrong Answer" << endl;
        }
        else
        {
            for(int i = 0; i < securityNum; i++)
            {
                if(!wasAlone[i])
                {
                    wasNoOne = true; 
                    break;
                }
            }
            if(wasNoOne)
                fout << "Wrong Answer" << endl;
            else  
                fout << "Accepted" << endl;
        }
    }
    fout.close();
}
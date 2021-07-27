#include <iostream>
#include <tuple>
#include <set>
#include <unordered_set>
using namespace std;

const short MINAGE = 18, MAXAGE = 80;
enum Events : short
{
    DEATH, BIRTH
};
using Date = tuple<short, short, short>;
using Event = tuple<Date, Events, short>;

inline void ShowPeople(const unordered_set<short>& p)
{
    for(auto& index : p)
        cout << index << " ";
    cout << endl;
}

int main()
{
    unsigned short N;
    cin >> N;
    set<Event> people; //y.m.d, type, index
    
    Date birthD, deathD;
    auto&[yd, md, dd] = deathD;
    auto&[yb, mb, db] = birthD;
    for(short i = 1; i <= N; i++)
    {
        cin >> db >> mb >> yb;
        cin >> dd >> md >> yd;
        yb += MINAGE;
        if(birthD < deathD)
        {
            people.insert(make_tuple(birthD, BIRTH, i));
            yb += MAXAGE - MINAGE;
            people.insert(make_tuple(min(deathD, birthD), DEATH, i));
        }
    }

    if(!people.size())
    {
        cout << 0;
    }
    else  
    {
        unordered_set<short> inCurrSet;
        bool lastEvent = false; 
        for(auto&[date, type, index] : people)
        {
            if(type)
            {
                inCurrSet.insert(index);
            }
            else  
            {
                if(lastEvent)
                    ShowPeople(inCurrSet);
                inCurrSet.erase(index);
            }
            lastEvent = type; 
        }
    }
}
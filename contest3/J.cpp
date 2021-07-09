#include <iostream>
#include <utility>
#include <math.h>
#include <set>
using namespace std;

void Intersection(int first[4], int second[4])
{
    for(int i = 0; i < 4; i++)
    {
        if(i % 2 == 0)
            first[i] = (first[i] > second[i])? first[i] : second[i];
        else  
            first[i] = (first[i] < second[i])? first[i] : second[i];
    }
}

void Extend(int arr[4], const int& step)
{
    for(int i = 0; i < 4; i++)
    {
        arr[i] -= (int)pow(-1, i) * step;
    }
}

int main()
{
    int pos[4]{0}; //{min-, max-, min+, max+}
    set<std::pair<int, int>> answ; 
    int t, d, n;
    cin >> t >> d >> n; 

    for(int i = 0; i < n; i++)
    {
        Extend(pos, t);

        int newX, newY;
        cin >> newX >> newY;
        int newPos[4] = {newX - newY, newX - newY, newX + newY, newX + newY};
        Extend(newPos, d);
        Intersection(pos, newPos);
    }

    for(int minus = pos[0]; minus <= pos[1]; minus++)
        for(int plus = pos[2]; plus <= pos[3]; plus++)
            if((minus + plus) % 2 == 0)
                answ.insert(make_pair((minus + plus) / 2, plus - (minus + plus) / 2));
    
    cout << answ.size() << endl;
    for(auto& p : answ)
        cout << p.first << " " << p.second << endl;
}
#include <iostream>
#include <set>
using namespace std;

inline void showAnsw(set<int>& s)
{
    cout << s.size() << endl;
    for(auto& b : s)
        cout << b << " ";
    cout << endl;
}

int main()
{
    int N, M, num; //Ann, Bor
    cin >> N >> M; 
    set<int> Ann, Bor, res; 
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        Ann.insert(num); 
    }
    for(int i = 0; i < M; i++)
    {
        cin >> num;
        if(Ann.find(num) != Ann.end())
        {
            res.insert(num);
            Ann.erase(num); 
        }  
        else
        {
            Bor.insert(num);
        }
    }

    showAnsw(res);
    showAnsw(Ann);
    showAnsw(Bor);
}
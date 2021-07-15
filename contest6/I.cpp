#include <iostream>
#include <algorithm>
using namespace std;

inline bool checkInconvenienceFactor(int incFactor, const int* params)
{
    int brigadesCount = 0, membersNumber = params[2];
    for(int i = 3; i <= params[0] + 3 - membersNumber;)
    {
        if(params[i + membersNumber - 1] - params[i] <= incFactor)
        {
            brigadesCount++;
            i += membersNumber;
        }
        else  
        {
            i++;
        }
    }
    return brigadesCount >= params[1]; // current count >= required count
}

int LBinSearch(int l, int r, bool(*check)(int, const int*),const int* checkParams)
{
    int m;
    while(l < r)
    {
        m = (l + r) / 2;
        if(check(m, checkParams))
            r = m;
        else  
            l = m + 1;
    }
    return l;
}

int main()
{
    //N - num of students, R - num of brigades, C - num of students in a brigade, h1 .. hN
    int N;
    cin >> N;
    int* students = new int[N + 3];
    students[0] = N;
    for(int i = 1; i < N + 3; i++)
        cin >> students[i];
    
    sort(students + 3, students + 3 + N);
    cout << LBinSearch(0, students[N + 2] - students[3], checkInconvenienceFactor, students);

    delete[] students;
}
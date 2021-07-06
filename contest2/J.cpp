#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int N;
    long double frPrev, frNext;
    long double left = 30., right = 4000.; 
    string str; 
    cin >> N >> frPrev; 
    for(int i = 0; i < N - 1; i++)
    {
        cin >> frNext; 
        cin >> str; 
        if(str == "closer")
        {
            if(frNext > frPrev)
                left = max(left, (frNext + frPrev) / 2);
            else  
                right = min(right, (frPrev + frNext) / 2);
        }
        else  
        {
            if(frNext > frPrev)
                right = min(right, (frPrev + frNext) / 2);
            else  
                left = max(left, (frNext + frPrev) / 2);
        }
        frPrev = frNext; 
    }
    // cout << left << " " << right; 
    printf("%LF %LF", left, right);
}
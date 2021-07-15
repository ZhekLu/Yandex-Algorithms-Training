#include <iostream>
#include <map>
using namespace std;

int main()
{
    unsigned long long cardsNum, maxDifferFactor; //n, k
    cin >> cardsNum >> maxDifferFactor;
    map<unsigned, unsigned> cards;  //[digit, quantity]
    for(int i = 0; i < cardsNum; i++)
    {
        unsigned number; 
        cin >> number;
        cards[number]++;
    }

    unsigned long long answer = 0;
    long long duplicates = 0, dist = -1; // dist - quantity of unic values between (l & r)
    for(auto l = cards.begin(), r = cards.begin(); l != cards.end(); l++, dist--)
    {
        while(r != cards.end() && l->first * maxDifferFactor >= r->first)
        {
            duplicates += (r->second > 1)? 1 : 0;
            r++; dist++;
        } 
        if(l->second > 1)
            duplicates--;
        if(l->second > 1)
            answer += dist * 3;
        if(l->second > 2)
            answer++;
        answer += dist * (dist - 1) * 3;
        answer += duplicates * 3;
    }
    cout << answer; 
}
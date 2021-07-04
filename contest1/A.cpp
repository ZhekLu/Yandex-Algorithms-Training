#include <iostream>
#include <string>
using namespace std;
int main()
{
    int troom, tcond;
    string mode;
    cin >> troom >> tcond;
    cin >> mode;
    if (mode == "freeze")
    {
        if (troom > tcond)
            cout << tcond;
        else
            cout << troom;
    }
    else if (mode == "heat")
    {
        if (troom < tcond)
            cout << tcond;
        else
            cout << troom;
    }
    else if (mode == "auto")
        cout << tcond;
    else if (mode == "fan")
        cout << troom;
}
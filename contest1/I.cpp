#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a, b, c, d, e; 
	int brick[3], hole[2];
	for (int i = 0; i < 3; i++)
		cin >> brick[i]; 
	for (int i = 0; i < 2; i++)
		cin >> hole[i];
	sort(brick, brick + 3); 
	sort(hole, hole + 2); 
	cout << ((hole[0] < brick[0] || hole[1] < brick[1]) ? "NO" : "YES");
}
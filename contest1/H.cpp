#include <iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	int a, b, n, m; 
	cin >> a >> b >> n >> m;
	int time_n[]{ a * (n - 1) + n, a * (n + 1) + n};
	int time_m[]{ b * (m - 1) + m, b * (m + 1) + m};
	int minLim = max(time_n[0], time_m[0]),
		maxLim = min(time_n[1], time_m[1]);
	if (minLim <= maxLim)
		cout << minLim << " " << maxLim;
	else
		cout << -1; 
	return 0;
}
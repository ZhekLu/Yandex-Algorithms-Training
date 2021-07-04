#include <iostream>
#include<math.h>
using namespace std;

int main()
{
	//int l1, h1, l2, h2;
	int size[4];
	for (int i = 0; i < 4; i++)
		cin >> size[i];
	int compare[4][3];
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
		{
			compare[i][0] = (size[i] > size[i + 2]) ? size[i] : size[i + 2];
			compare[i][1] = size[i + 1] + size[(i + 3) % 4];
		}
		else
		{
			compare[i][0] = (size[(i - (int)pow(-1, 4 % i)) % 4] > size[i]) ? size[(i - (int)pow(-1, 4 % i)) % 4] : size[i];
			compare[i][1] = size[(i + 2) % 4] + size[(i + (int)pow(-1, 4 % i)) % 4];
		}
		compare[i][2] = compare[i][0] * compare[i][1];
	}
	int len = compare[0][0];
	int hei = compare[0][1];
	int min = compare[0][2];
	for (int i = 1; i < 4; i++)
	{
		if (compare[i][2] < min)
		{
			len = compare[i][0];
			hei = compare[i][1];
			min = compare[i][2];
		}
	}

	cout << len << " " << hei; 
}
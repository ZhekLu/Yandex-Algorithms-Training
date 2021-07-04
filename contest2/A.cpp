#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool isMonotone(vector<int>& str, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (str[i] >= str[i + 1])
			return false;
	}
	return true;
}

int main()
{
	vector<int> arr; 
	ifstream fin("input.txt");
	if (fin.is_open())
	{
		int num;
		while (fin >> num)
			arr.push_back(num);
		fin.close();
		cout << ((isMonotone(arr, arr.size())) ? "YES" : "NO");
	}
	return 0;
}
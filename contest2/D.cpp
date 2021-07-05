#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int isGreaterThanNeigh(vector<int>& arr)
{
	int counter = 0; 
	for (int i = 1; i < arr.size() - 1; i++)
	{
		if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
			counter++; 
	}
	return counter; 
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
		cout << isGreaterThanNeigh(arr);
	}
	return 0;
}
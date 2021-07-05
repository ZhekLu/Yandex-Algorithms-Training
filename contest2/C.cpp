#include <iostream>
using namespace std;

int nearestNum(int* arr, int len, int num)
{
	int nearest = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (abs(num - arr[i]) < abs(num - nearest))
			nearest = arr[i]; 
	}
	return nearest;
}

int main()
{
	int* arr, size, number;
	cin >> size; 
	arr = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	cin >> number; 
	cout << nearestNum(arr, size, number);
}
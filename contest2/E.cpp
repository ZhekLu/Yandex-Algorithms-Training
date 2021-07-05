#include <iostream>
using namespace std;

int countPlace(const int* arr, int size)
{
	int before = -1, driver = -1;
	for (int i = 0; i < size - 2; i++)
	{
		if (arr[i] > before)
		{
			before = arr[i];
			driver = -1;
		}
		if (arr[i + 1] % 10 == 5 && arr[i + 1] > driver && arr[i + 2] < arr[i + 1])
			driver = arr[i + 1];
	}
	if (driver == -1)
		return 0;
	int place = 1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > driver)
			place++;
	}
	return place;
}

int main()
{
	int* arr, N;
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cout << countPlace(arr, N);
	return 0;
}
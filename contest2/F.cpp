#include <iostream>
using namespace std;

char* toSymmetric(const int* arr, int size, int& quantity)
{
	for (int i = 0; i < size; i++)
	{
		int k = i, j = size - 1;
		for(; k < size && j > 0 && arr[k] == arr[j] && k <= j; k++, j--)
		{ }
		if (k > j)
		{
			quantity = i--;
			char* res = new char[quantity];
			for (k = 0; i >= 0; i--, k++)
			{
				res[k] = arr[i] + '0';
			}
			return res; 
		}
	}
}

int main()
{
	int* arr, N;
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int q = 0;
	char* ans = toSymmetric(arr, N, q);
	cout << q << endl;
	for (int i = 0; i < q; i++)
		cout << ans[i] << " ";
	return 0;
}
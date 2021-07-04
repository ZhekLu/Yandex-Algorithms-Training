#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
enum Type
{
	CONSTANT, ASCENDING, WASCENDING, 
	DESCENDING, WDESCENDING, RANDOM
};

int typeOfSequence(vector<long>& str, int len)
{
	bool type[6];
	for (int i = 0; i < 6; i++)
		type[i] = true; 
	for (int i = 0; i < len - 1; i++)
	{
		if (str[i] == str[i + 1])
		{
			type[DESCENDING] = false;
			type[ASCENDING] = false;
		}
		if (str[i] > str[i + 1])
		{
			type[ASCENDING] = false;
			type[WASCENDING] = false; 
			type[CONSTANT] = false;
		}
		else if (str[i] < str[i + 1])
		{
			type[DESCENDING] = false;
			type[WDESCENDING] = false;
			type[CONSTANT] = false;
		}
	}
	for (int i = 0; i < 6; i++)
		if (type[i])
			return i;
}

int main()
{
	vector<long> arr; 
	ifstream fin("input.txt");
	if (fin.is_open())
	{
		long num;
		while (fin >> num && num != -2000000000)
			arr.push_back(num);
		fin.close();
		switch (typeOfSequence(arr, arr.size()))
		{
		case CONSTANT:
			cout << "CONSTANT"; 
			break;
		case ASCENDING:
			cout << "ASCENDING";
			break;
		case DESCENDING:
			cout << "DESCENDING";
			break;
		case WASCENDING:
			cout << "WEAKLY ASCENDING";
			break;
		case WDESCENDING:
			cout << "WEAKLY DESCENDING";
			break;
		case RANDOM:
			cout << "RANDOM";
			break;
		}
	}
	return 0;
}
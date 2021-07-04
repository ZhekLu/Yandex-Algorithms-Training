#include <iostream>
#include <string>
using namespace std;

void getCodeNum(const string& from, string& code, string& num);

int main()
{
	string number, book[3];
	string numCode, numNum, bookCode, bookNum; 
	cin >> number >> book[0] >> book[1] >> book[2]; 
	getCodeNum(number, numCode, numNum);
	for (int i = 0; i < 3; i++)
	{
		getCodeNum(book[i], bookCode, bookNum);
		if (numCode == bookCode && numNum == bookNum)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
}

void getCodeNum(const string& from, string& code, string& num)
{ 
	string clearNum = "";
	code = ""; num = "";
	for (int i = 0; i < from.length(); i++)
		if (from[i] >= 48 && from[i] <= 57)
			clearNum += from[i];
		
	switch (clearNum.length())
	{
	case 7:
		code = "495";
		num = clearNum;
		break;
	case 11:
		clearNum.erase(0, 1);
	case 10:
		for (int i = 0; i < 3; i++)
			code += clearNum[i];
		clearNum.erase(0, 3);
		num = clearNum; 
		break; 
	}
}

#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	string str;
	while (1)
	{
		getline(cin, str);
		if (str == "")
			break;
		cout << str << endl;
	}
}
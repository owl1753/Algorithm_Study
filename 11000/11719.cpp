#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		cout << str << "\n";
	}
}
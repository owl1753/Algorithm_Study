#include <iostream>
using namespace std;

int main()
{
	int n, min = 0;
	cin >> n;
	n = 1000 - n;
	min += n / 500;
	n %= 500;
	min += n / 100;
	n %= 100;
	min += n / 50;
	n %= 50;
	min += n / 10;
	n %= 10;
	min += n / 5;
	n %= 5;
	min += n / 1;
	n %= 1;
	cout << min;
}
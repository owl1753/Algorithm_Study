#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << fixed;
	cout.precision(32);
	cout << a / (double)b;
}
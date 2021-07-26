#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	if (((a % 10) * 100) + ((a / 10 % 10) * 10) + (a / 100) > ((b % 10) * 100) + ((b / 10 % 10) * 10) + (b / 100))
	{
		cout << ((a % 10) * 100) + ((a / 10 % 10) * 10) + (a / 100);
	}
	else
	{
		cout << ((b % 10) * 100) + ((b / 10 % 10) * 10) + (b / 100);
	}
}
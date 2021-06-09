#include <iostream>
using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if (a < x)
		{
			cout << a << " ";
		}
	}
}
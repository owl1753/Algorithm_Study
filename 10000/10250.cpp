#include <iostream>
using namespace std;

int main()
{
	int t, h, w, n, a1, a2;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> h >> w >> n;
		if (n % h == 0)
		{
			a1 = h;
			a2 = n / h;
		}
		else
		{
			a1 = n % h;
			a2 = (n / h) + 1;
		}
		if (a2 / 10 == 0)
			cout << a1 << 0 << a2 << "\n";
		else
			cout << a1 << a2 << "\n";
	}
}
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int check[10001];

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	check[1] = 1;
	for (int i = 2; i < 10001; i++)
	{
		if (check[i] == 1)
			continue;
		for (int j = i + i; j < 10001; j += i)
			check[j] = 1;
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n, x = 0, y = 10001;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == 0 && check[n - i] == 0 && y - x > abs(n - i - i))
			{
				x = i;
				y = n - i;
			}
		}
		cout << x << " " << y << "\n";
	}
}
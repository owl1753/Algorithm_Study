#include <iostream>
#include <math.h>
using namespace std;
#define MAX 10001

int main()
{
	int m, n, min = MAX, sum = 0;
	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		int flag = 1;
		if (i == 1 || (i % 2 == 0 && i != 2))
			continue;
		else if (i != 2)
		{
			int sqrtn = sqrt(i);
			for (int j = 3; j <= sqrtn; j += 2)
			{
				if (i % j == 0)
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag == 1)
		{
			sum += i;
			if (i < min)
			{
				min = i;
			}
		}
	}
	if (sum == 0)
		cout << -1;
	else
	{
		cout << sum << "\n";
		cout << min << "\n";
	}
}
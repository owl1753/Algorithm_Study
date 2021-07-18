#include <iostream>
using namespace std;

int main()
{
	int n, minus = 0, cnt = 0, t = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		t = i;
		if (t / 100 != 0)
		{
			minus = (t % 10) - ((t % 100) / 10);
			while (1)
			{
				if (t / 10 == 0)
				{
					cnt++;
					break;
				}

				if (t / 100 == 0)
				{
					if (minus != (t % 10) - (t / 10))
					{
						break;
					}
				}
				else
				{
					if (minus != (t % 10) - ((t % 100) / 10))
					{
						break;
					}
				}
				t = t / 10;
			}
			minus = 0;
		}
		else
		{
			cnt++;
		}
	}
	cout << cnt;
}

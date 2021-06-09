#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 0;
	cin >> n;
	if (n % 5 == 0)
	{
		cout << n / 5;
	}
	else
	{
		for (int i = n / 5; i >= 0; i--)
		{
			if ((n - (i * 5)) % 3 == 0)
			{
				cnt = i + (n - (i * 5)) / 3;
				break;
			}
		}
		if (cnt == 0)
			cout << -1;
		else
			cout << cnt;
	}
}
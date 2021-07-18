#include <iostream>
using namespace std;

int main()
{
	int x, cnt = 1, n1, n2, flag = 0;
	cin >> x;
	for (int i = 1; ; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i % 2 == 0)
			{
				n1 = j;
				n2 = i + 1 - j;
			}
			else
			{
				n1 = i + 1 - j;
				n2 = j;
			}
			if (cnt == x)
			{
				flag = 1;
				break;
			}
			cnt++;
		}
		if (flag == 1)
			break;
	}
	cout << n1 << "/" << n2;
}
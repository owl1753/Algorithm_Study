#include <iostream>
using namespace std;

void sam(int n, int t, int sum, int* cnt)
{
	if (n == t)
	{
		if (sum % 3 == 0)
		{
			*cnt = *cnt + 1;
			return;
		}
		else
		{
			return;
		}
	}
	sam(n, t + 1, sum, cnt);
	sam(n, t + 1, sum + 1, cnt);
	sam(n, t + 1, sum + 2, cnt);
}
int main()
{
	int n, sum = 0, t = 0, cnt = 0;
	cin >> n;
	sam(n, t + 1, sum + 1, &cnt);
	sam(n, t + 1, sum + 2, &cnt);
	cout << cnt;
}
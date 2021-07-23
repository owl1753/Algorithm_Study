#include <iostream>
using namespace std;

int main()
{
	int dp[41] = { 0 };
	int fix[41] = { 0 };
	int n, m, index = 1;
	long long sum = 1;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int t;
		cin >> t;
		fix[t] = 1;
	}
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	for (int i = 1; i <= n; i++)
	{
		if (fix[i] != 1)
		{
			if (fix[i + 1] == 1 || i == n)
			{
				sum *= dp[index];
				index = 0;
			}
			index++;
		}
	}
	cout << sum;
}
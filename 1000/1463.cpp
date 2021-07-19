#include <iostream>
using namespace std;

int main()
{
	int* dp = new int[1000001];
	int n;
	cin >> n;
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 0;
		if (i % 3 == 0)
		{
			dp[i] = dp[i / 3] + 1;
		}
		if (i % 2 == 0)
		{
			if (dp[i] == 0 || dp[i] > dp[i / 2] + 1)
			{
				dp[i] = dp[i / 2] + 1;
			}
		}
		if (dp[i] == 0 || dp[i] > dp[i - 1] + 1)
		{
			dp[i] = dp[i - 1] + 1;
		}
	}
	cout << dp[n];
}
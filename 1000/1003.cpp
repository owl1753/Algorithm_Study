#include <iostream>
using namespace std;

int main()
{
	int t, n;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int dp[41], n;
		cin >> n;
		dp[0] = 0;
		dp[1] = 1;
		for (int j = 2; j <= n; j++)
		{
			dp[j] = dp[j - 1] + dp[j - 2];
		}
		if (n == 0)
		{
			cout << 1 << " " << 0 << "\n";
		}
		else if (n == 1)
		{
			cout << 0 << " " << 1 << "\n";
		}
		else
		{
			cout << dp[n - 1] << " " << dp[n] << "\n";
		}
	}
}
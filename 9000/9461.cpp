#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		long long dp[101];
		int n;
		cin >> n;
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 1;
		for (int i = 3; i < n; i++)
		{
			dp[i] = dp[i - 2] + dp[i - 3];
		}
		cout << dp[n - 1] << "\n";
	}
}
#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int dp[11];
		dp[0] = 1;
		dp[1] = 2;
		dp[2] = 4;
		int n;
		cin >> n;
		for (int j = 3; j < n; j++)
		{
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		cout << dp[n - 1] << "\n";
	}
}
#include <iostream>
using namespace std;

int main(void) {
	int dp[301];
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i < a)
		{
			dp[i] = 0;
		}
		else if (a == i || b == i || c == i)
		{
			dp[i] = 1;
		}
		else if (dp[i - a] == 1 || dp[i - b] == 1 || dp[i - c] == 1)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = 0;
		}
	}
	cout << dp[n];
}
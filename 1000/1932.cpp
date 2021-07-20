#pragma warining(disable:4996)
#include <iostream>
using namespace std;

int dp[501][501];
int tri[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, max = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> tri[i][j];
		}
	}
	dp[1][1] = tri[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				dp[i][j] = tri[i][j] + dp[i - 1][j];
			}
			else if (j == i)
			{
				dp[i][j] = tri[i][j] + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = tri[i][j] + (dp[i - 1][j - 1] >= dp[i - 1][j] ? dp[i - 1][j - 1] : dp[i - 1][j]);
			}
			if (dp[i][j] > max)
			{
				max = dp[i][j];
			}
		}
	}
	cout << max;
}
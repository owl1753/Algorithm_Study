#pragma warining(disable:4996)
#include <iostream>
using namespace std;

int main()
{
	int **dp = new int*[1001];
	for (int i = 0; i < 1001; i++)
	{
		dp[i] = new int[1001];
	}
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				dp[i][j] = 1;
			else
				dp[i][j] = ((dp[i - 1][j] + dp[i - 1][j - 1]) % 10007);
		}
	}
	cout << dp[n][k];
}
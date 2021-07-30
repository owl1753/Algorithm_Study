#include <iostream>
using namespace std;
#define MAX 1001

int map[MAX][MAX];
int dp[MAX][MAX];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	dp[1][1] = map[1][1];
	for (int i = 2; i <= m; i++)
	{
		dp[1][i] = dp[1][i - 1] + map[1][i];
	}
	for (int i = 2; i <= n; i++)
	{
		dp[i][1] = dp[i - 1][1] + map[i][1];
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			if (dp[i - 1][j] + map[i][j] > dp[i][j])
				dp[i][j] = dp[i - 1][j] + map[i][j];
			if (dp[i][j - 1] + map[i][j] > dp[i][j])
				dp[i][j] = dp[i][j - 1] + map[i][j];
			if (dp[i - 1][j - 1] + map[i][j] > dp[i][j])
				dp[i][j] = dp[i - 1][j - 1] + map[i][j];
		}
	}
	cout << dp[n][m];
}
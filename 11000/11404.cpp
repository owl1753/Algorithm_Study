#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int dp[101][101];
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = i == j ? 0 : INF;

	for (int i = 1; i <= m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		dp[a][b] = min(dp[a][b], w);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == INF)
				cout << "0 ";
			else
				cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
}
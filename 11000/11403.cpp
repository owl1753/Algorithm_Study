#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF 987654321

int adj[101][101];
int dp[101][101];
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> adj[i][j];
			dp[i][j] = adj[i][j] == 0 ? INF : 1;
		}
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
				cout << "1 ";
		}
		cout << "\n";
	}
}
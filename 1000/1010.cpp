#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int dp[31][31];
		int n, m;
		cin >> n >> m;
		for (int i = 0; i <= 30; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}
		if (n == 0 || m == 0)
			cout << 0 << "\n";
		else
			cout << dp[m][n] << "\n";
	}
}
#include <iostream>
using namespace std;

int arr[1025][1025];
int dp[1025][1025];
int n, m;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (i == 1 && j == 1) dp[i][j] = arr[i][j];
			else if (i == 1) dp[i][j] = dp[i][j - 1] + arr[i][j];
			else if (j == 1) dp[i][j] = dp[i - 1][j] + arr[i][j];
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
		}
	}
	while (m--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << "\n";
	}
}
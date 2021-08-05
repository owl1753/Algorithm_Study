#include <iostream>
using namespace std;
#define ll long long
const int MOD = 1000000007;

ll dp[2020][3];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[1][1] = 1;
	dp[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != n)
				dp[i][(j + 1) % 3] += dp[i - 1][j] % MOD;
			dp[i][(j + 5) % 3] += dp[i - 1][j] % MOD;
		}
	}
	cout << dp[n][0];
}
#include <iostream>
using namespace std;
#define ll long long
const int MOD =  1000000009;

ll dp[44444];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[1] = 0;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] * 3) % MOD;
	}
	cout << dp[n];
}
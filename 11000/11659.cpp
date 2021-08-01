#include <iostream>
using namespace std;

int arr[200001];
int dp[200001];
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + arr[i];
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << dp[j] - dp[i - 1] << "\n";
	}
}
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001][2];
int dp[100001][2];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i][0];
		for (int i = 0; i < n; i++) cin >> arr[i][1];
		for (int i = 0; i < n; i++) {
			dp[i][0] = 0;
			dp[i][1] = 0;
		}

		for (int i = 0; i < n; i++) {
			if (i == 0) {
				dp[i][0] = arr[i][0];
				dp[i][1] = arr[i][1];
			}
			if (i >= 1) {
				dp[i][0] = max(dp[i][0], dp[i - 1][1] + arr[i][0]);
				dp[i][1] = max(dp[i][1], dp[i - 1][0] + arr[i][1]);
			}
			if (i >= 2) {
				dp[i][0] = max(dp[i][0], dp[i - 2][0] + arr[i][0]);
				dp[i][0] = max(dp[i][0], dp[i - 2][1] + arr[i][0]);
				dp[i][1] = max(dp[i][1], dp[i - 2][1] + arr[i][1]);
				dp[i][1] = max(dp[i][1], dp[i - 2][0] + arr[i][1]);
			}
		}

		cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
	}

	
}
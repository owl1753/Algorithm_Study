#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001][2];
int n, result = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0][0] = 1;
	dp[0][1] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
				dp[i][1] = max(dp[i][1], 1);
			}
			else if (arr[i] < arr[j]) {
				dp[i][0] = max(dp[i][0], 1);
				dp[i][1] = max(dp[i][1], dp[j][0] + 1);
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
			else {
				dp[i][0] = max(dp[i][0], 1);
				dp[i][1] = max(dp[i][1], 1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		result = max(result, dp[i][0]);
		result = max(result, dp[i][1]);
	}
	cout << result;
}
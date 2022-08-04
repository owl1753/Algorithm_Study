#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001];
string a, b;
int result = 0;

int main() {
	cin >> a;
	cin >> b;
	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				if (i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				if (i != 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				if (j != 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			}
		}
	}
	for (int i = 0; i < b.length(); i++) result = max(result, dp[a.length() - 1][i]);
	cout << result;
}
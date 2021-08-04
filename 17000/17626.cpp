#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int dp[50001];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= 224; i++) {
		v.push_back(i * i);
	}
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int tmp = 987654321;
		for (int j = 0; j < v.size() && v[j] <= i; j++) {
			tmp = dp[i - v[j]] < tmp ? dp[i - v[j]] : tmp;
		}
		dp[i] = tmp + 1;
	}
	cout << dp[n];
}
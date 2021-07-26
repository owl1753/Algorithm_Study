#include <iostream>
using namespace std;
#define MAX 1001
#define MOD 1234567


int dp[MAX][10];
int n, t;

int main() {
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= MAX - 1; i++)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][4]) % MOD;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % MOD;
		dp[i][3] = (dp[i - 1][2] + dp[i - 1][6]) % MOD;
		dp[i][4] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % MOD;
		dp[i][5] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % MOD;
		dp[i][6] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % MOD;
		dp[i][7] = (dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0]) % MOD;
		dp[i][8] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]) % MOD;
		dp[i][9] = (dp[i - 1][6] + dp[i - 1][8]) % MOD;
		dp[i][0] = dp[i - 1][7] % MOD;
	}
	scanf("%d", &t);
	while (t--) {
		int result = 0;
		scanf("%d", &n);
		for (int i = 0; i < 10; i++)
			result += dp[n][i];
		printf("%d\n", result % MOD);
	}
}
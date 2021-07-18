#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 1001

int dp[MAX][3];
int r[MAX];
int g[MAX];
int b[MAX];

int min(int a, int b)
{
	return (a < b ? a : b);
}

int main()
{
	int n, result;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &r[i], &g[i], &b[i]);
	dp[1][0] = r[1];
	dp[1][1] = g[1];
	dp[1][2] = b[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g[i];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
	}
	result = ((dp[n][0] < dp[n][1] ? dp[n][0] : dp[n][1]) < dp[n][2]) ? (dp[n][0] < dp[n][1] ? dp[n][0] : dp[n][1]) : dp[n][2];
	printf("%d", result);
}

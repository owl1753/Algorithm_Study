#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 2001

int arr[MAX];
int dp[MAX][MAX];

int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++)
		dp[i][i] = 1;
	for (int i = 2; i <= n; i++)
		dp[i - 1][i] = dp[i][i - 1] = arr[i] == arr[i - 1] ? 1 : 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1])
					dp[i + j][j] = dp[j][i + j] = 1;
		}
	}
	scanf("%d", &m);
	while(m--)
	{
		int s, e;
		scanf("%d%d", &s, &e);
		printf("%d\n", dp[s][e]);
	}
}
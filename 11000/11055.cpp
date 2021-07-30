#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int A[1000];
	int dp[1001] = { 0 };
	int n, result, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	dp[0] = A[0];
	result = dp[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (A[i] > A[j] && max < dp[j])
			{
				max = dp[j];
				dp[i] = dp[j] + A[i];
			}
		}
		if (dp[i] == 0)
		{
			dp[i] = A[i];
		}
		if (result < dp[i])
		{
			result = dp[i];
		}
		max = 0;
	}
	cout << result;
}
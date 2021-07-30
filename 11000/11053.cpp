#include <iostream>
using namespace std;

int main()
{
	int dp[1001];
	int arr[1000], n, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] < arr[i] && max < dp[j])
				max = dp[j];
		}
		dp[i] = max + 1;
		max = 0;
	}
	max = dp[0];
	for (int i = 0; i < n; i++)
	{
		if (dp[i] > max)
			max = dp[i];
	}
	cout << max;
}
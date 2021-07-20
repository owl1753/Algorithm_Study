#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[100000];
	int dp[100001];
	int n, max;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dp[0] = arr[0];
	max = dp[0];
	for (int i = 1; i < n; i++)
	{
		if (dp[i - 1] + arr[i] > arr[i])
			dp[i] = dp[i - 1] + arr[i];
		else
			dp[i] = arr[i];
		if (max < dp[i])
			max = dp[i];
	}
	cout << max;
}
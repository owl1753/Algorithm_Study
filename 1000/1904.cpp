#include <iostream>
using namespace std;

int dp[1000001];

int tile(int n)
{
	if (dp[n] != NULL)
		return dp[n];
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return dp[n] = (tile(n - 1) + tile(n - 2)) % 15746;
}

int main()
{
	int n;
	cin >> n;
	cout << tile(n);
}
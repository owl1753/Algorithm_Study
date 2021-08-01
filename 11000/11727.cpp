#include <iostream>
using namespace std;

int dp[1010];

int tile(int n)
{
	if (dp[n] != 0)
		return dp[n];
	if (n == 0 || n == 1)
		return 1;
	return dp[n] = (tile(n - 1) + (2 * tile(n - 2))) % 10007;
}

int main()
{
	int n;
	cin >> n;
	cout << tile(n);
}
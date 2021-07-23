#include <iostream>
using namespace std;

int main()
{
	long long dp0[101];
	long long dp1[101];
	int n;
	cin >> n;
	dp1[0] = 1;
	dp0[0] = 0;
	for (int i = 1; i < n; i++)
	{
		dp1[i] = dp0[i - 1];
		dp0[i] = dp0[i - 1] + dp1[i - 1];
	}
	cout << dp0[n - 1] + dp1[n - 1];
}
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101

struct Object
{
	int w, v;
};

Object arr[MAX];
int dp[MAX][MAX * 1000];
int n, k;

int bag(int w, int i)
{
	int n1 = 0, n2 = 0;
	if (dp[i][w] > 0)
		return dp[i][w];
	if (i == n)
		return 0;
	if (w + arr[i].w <= k)
		n1 = arr[i].v + bag(w + arr[i].w, i + 1);
	n2 = bag(w, i + 1);
	return dp[i][w] = max(n1, n2);
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].w >> arr[i].v;
	}
	cout << bag(0, 0);
}
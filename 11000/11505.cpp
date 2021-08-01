#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#define MAX 4000001
#define MOD 1000000007
#define ll long long

ll tree[MAX];
ll arr[MAX];
int n, m, k;

ll init(int start, int end, int index)
{
	if (start == end)
		return tree[index] = arr[start];
	int mid = (start + end) / 2;
	return tree[index] = (init(start, mid, index * 2) * init(mid + 1, end, index * 2 + 1)) % MOD;
}

ll update(int start, int end, int index, int target, ll diff)
{
	if (target < start || target > end)
		return tree[index];
	if (start == end)
		return tree[index] = diff;
	int mid = (start + end) / 2;
	return tree[index] = (update(start, mid, index * 2, target, diff) * update(mid + 1, end, index * 2 + 1, target, diff)) % MOD;

}

ll mul(int start, int end, int left, int right, int index)
{
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[index];
	int mid = (start + end) / 2;
	return (mul(start, mid, left, right, index * 2) * mul(mid + 1, end, left, right, index * 2 + 1)) % MOD;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (ll i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);
	init(1, n, 1);
	m += k;
	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1)
			update(1, n, 1, b, c);
		else
			printf("%lld\n", mul(1, n, b, c, 1));
	}
}
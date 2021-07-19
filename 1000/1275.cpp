#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 400001
#define ll long long

ll tree[MAX];
ll arr[MAX];

ll update(ll start, ll end, ll index, ll target, ll diff)
{
	if (target < start || target > end)
		return tree[index];
	if (start == end)
		return tree[index] = diff;
	int mid = (start + end) / 2;
	return tree[index] = update(start, mid, index * 2, target, diff) + update(mid + 1, end, index * 2 + 1, target, diff);
}

ll sum(ll start, ll end, ll index, ll left, ll right)
{
	if (end < left || start > right)
		return 0;
	if (left <= start && end <= right)
		return tree[index];
	int mid = (start + end) / 2;
	return sum(start, mid, index * 2, left, right) + sum(mid + 1, end, index * 2 + 1, left, right);
}

int main()
{
	ll n, q;
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &arr[i]);
		update(1, n, 1, i, arr[i]);
	}
	for (int i = 1; i <= q; i++)
	{
		ll x, y, a, b;
		scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
		if (x > y)
			printf("%lld\n", sum(1, n, 1, y, x));
		else
			printf("%lld\n", sum(1, n, 1, x, y));
		update(1, n, 1, a, b);
	}
}
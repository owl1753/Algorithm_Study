#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 4000001
#define ll long long

ll tree[MAX];
ll arr[MAX];

ll modify(ll start, ll end, ll index, ll target, ll diff)
{
	if (target < start || target > end)
		return tree[index];
	if (start == end)
		return tree[index] = diff;
	int mid = (start + end) / 2;
	return tree[index] = modify(start, mid, index * 2, target, diff) + modify(mid + 1, end, index * 2 + 1, target, diff);
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
	ll n, m;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 0)
			if (b > c)
				printf("%lld\n", sum(1, n, 1, c, b));
			else
				printf("%lld\n", sum(1, n, 1, b, c));
		else
			modify(1, n, 1, b, c);
	}
}
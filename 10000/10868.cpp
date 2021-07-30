#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 400001
#define INF 1000000001
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
	return tree[index] = min(update(start, mid, index * 2, target, diff), update(mid + 1, end, index * 2 + 1, target, diff));
}

ll query(ll start, ll end, ll index, ll left, ll right)
{
	if (end < left || start > right)
		return INF;
	if (left <= start && end <= right)
		return tree[index];
	int mid = (start + end) / 2;
	return min(query(start, mid, index * 2, left, right), query(mid + 1, end, index * 2 + 1, left, right));
}

int main()
{
	ll n, m;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &arr[i]);
		update(1, n, 1, i, arr[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", query(1, n, 1, a, b));
	}
}
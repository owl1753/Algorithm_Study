#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 400001
#define INF 1000000001
#define ll long long

ll maxtree[MAX];
ll mintree[MAX];
ll arr[MAX];

ll maxupdate(ll start, ll end, ll index, ll target, ll diff)
{
	if (target < start || target > end)
		return maxtree[index];
	if (start == end)
		return maxtree[index] = diff;
	int mid = (start + end) / 2;
	return maxtree[index] = max(maxupdate(start, mid, index * 2, target, diff), maxupdate(mid + 1, end, index * 2 + 1, target, diff));
}

ll minupdate(ll start, ll end, ll index, ll target, ll diff)
{
	if (target < start || target > end)
		return mintree[index];
	if (start == end)
		return mintree[index] = diff;
	int mid = (start + end) / 2;
	return mintree[index] = min(minupdate(start, mid, index * 2, target, diff), minupdate(mid + 1, end, index * 2 + 1, target, diff));
}

ll maxquery(ll start, ll end, ll index, ll left, ll right)
{
	if (end < left || start > right)
		return 0;
	if (left <= start && end <= right)
		return maxtree[index];
	int mid = (start + end) / 2;
	return max(maxquery(start, mid, index * 2, left, right), maxquery(mid + 1, end, index * 2 + 1, left, right));
}

ll minquery(ll start, ll end, ll index, ll left, ll right)
{
	if (end < left || start > right)
		return INF;
	if (left <= start && end <= right)
		return mintree[index];
	int mid = (start + end) / 2;
	return min(minquery(start, mid, index * 2, left, right), minquery(mid + 1, end, index * 2 + 1, left, right));
}

int main()
{
	ll n, m;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &arr[i]);
		maxupdate(1, n, 1, i, arr[i]);
		minupdate(1, n, 1, i, arr[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		printf("%lld %lld\n", minquery(1, n, 1, a, b), maxquery(1, n, 1, a, b));
	}
}
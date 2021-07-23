#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001
#define ll long long
using namespace std;

ll arr[MAX];
ll tree[MAX];
ll n, m, k;

void update(int index, ll diff)
{
	for (int i = index; i <= n; i += (i & -i))
		tree[i] += diff;
}

ll query(int index)
{
	ll ans = 0;
	for (int i = index; i > 0; i -= (i & -i))
		ans += tree[i];
	return ans;
}

int main()
{
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &arr[i]);
		update(i, arr[i]);
	}
	m += k;
	for (int i = 1; i <= m; i++)
	{
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1)
		{
			ll diff = c - arr[b];
			arr[b] = c;
			update(b, diff);
		}
		else if (a == 2)
		{
			printf("%lld\n", query(c) - query(b - 1));
		}
	}
}
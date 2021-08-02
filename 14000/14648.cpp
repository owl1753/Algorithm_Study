#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#define MAX 1010
#define ll long long

ll arr[MAX];
ll n, q;

int main()
{
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);
	while (q--)
	{
		ll choose;
		ll a, b, c, d, t, result = 0;
		scanf("%lld", &choose);
		scanf("%lld%lld", &a, &b);
		for (int i = a; i <= b; i++)
			result += arr[i];
		if (choose == 1)
		{
			t = arr[a];
			arr[a] = arr[b];
			arr[b] = t;
		}
		else if (choose == 2)
		{
			scanf("%lld%lld", &c, &d);
			for (int i = c; i <= d; i++)
				result -= arr[i];
		}
		printf("%lld\n", result);
	}
}
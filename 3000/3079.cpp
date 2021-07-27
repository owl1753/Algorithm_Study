#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100010
#define ll long long

ll T[MAX];
ll N, M, answer = 0;

int main()
{
	ll left = 1000000001, right = 0, mid = 0;
	scanf("%lld%lld", &N, &M);
	for (ll i = 1; i <= N; i++)
	{
		scanf("%lld", &T[i]);
		left = min(left, T[i]);
	}
	right = left * M;
	while (left <= right)
	{
		ll total = 0;
		mid = (left + right) / 2;
		for (int i = 1; i <= N; i++)
		{
			total += mid / T[i];
		}
		if (total >= M)
		{
			answer = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	printf("%lld", answer);
}
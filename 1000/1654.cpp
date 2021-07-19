#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10010
#define ll long long

ll lan[MAX];
ll K, N, answer = 0;

int main()
{
	ll left = 1, right = 0, mid = 0;
	scanf("%lld%lld", &K, &N);
	for (int i = 1; i <= K; i++)
	{
		scanf("%lld", &lan[i]);
		right = max(right, lan[i]);
	}
	while (left <= right)
	{
		ll total = 0;
		mid = (left + right) / 2;
		for (ll i = 1; i <= K; i++)
			total += lan[i] / mid;
		if (total >= N)
		{
			answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	printf("%lld", answer);
}
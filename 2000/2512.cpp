#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10001
#define ll long long

ll money[MAX];
ll N, M, total = 0, answer = 0;

int main()
{
	ll left = 1, right = 0, mid = 0;
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &money[i]);
		total += money[i];
		right = max(right, money[i]);
	}
	scanf("%lld", &M);
	if (total > M)
	{
		while (left <= right)
		{
			total = 0;
			mid = (left + right) / 2;
			for (int i = 1; i <= N; i++)
			{
				if (money[i] <= mid)
					total += money[i];
				else
					total += mid;
			}
			if (total <= M)
			{
				answer = mid;
				left = mid + 1;
			}
			else
				right = mid - 1;
		}
	}
	else
		answer = right;
	printf("%lld", answer);
}
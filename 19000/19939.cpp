#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 1001

int basket[MAX];

int main()
{
	int n, k, cnt = 0;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			basket[i]++;
			cnt++;
		}
	}
	while (cnt < n)
	{
		for (int i = k; i > 0; i--)
		{
			if (cnt == n)
				break;
			basket[i]++;
			cnt++;
		}
	}
	if (n < cnt)
		printf("-1");
	else
		printf("%d", basket[k] - basket[1]);
}
#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 16

int n;
int t[MAX];
int p[MAX];

int func(int i)
{
	if (n < i)
		return 0;
	int n1 = 0, n2 = 0;
	if (i + t[i] <= n + 1)
		n1 += func(i + t[i]) + p[i];
	n2 = func(i + 1);
	return max(n1, n2);
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d%d", &t[i], &p[i]);
	printf("%d", func(1));
}

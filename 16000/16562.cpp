#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 10001

int par[MAX];
int money[MAX];
int check[MAX];

int find(int n)
{
	if (par[n] == -1) return n;
	return par[n] = find(par[n]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	par[a] = b;
}

int main()
{
	memset(par, -1, sizeof(par));
	int N, M, k, total = 0;
	scanf("%d%d%d", &N, &M, &k);
	for (int i = 1; i <= N; i++)
		scanf("%d", &money[i]);
	for (int i = 1; i <= M; i++)
	{
		int v, w;
		scanf("%d%d", &v, &w);
		merge(v, w);
	}
	for (int i = 1; i <= N; i++)
	{
		if (check[i] == 1)
			continue;
		int min = money[i];
		for (int j = i + 1; j <= N; j++)
		{
			if (find(i) == find(j))
			{
				check[j] = 1;
				if (min > money[j])
					min = money[j];
			}
		}
		total += min;
	}
	if (total <= k)
		printf("%d", total);
	else
		printf("Oh no");
}
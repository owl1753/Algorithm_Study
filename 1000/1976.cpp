#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 201

int par[MAX];
int trip[MAX * 10];

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
	int n, m, flag = 1;
	scanf("%d%d", &n, &m);
	memset(par, -1, sizeof(par));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int x;
			scanf("%d", &x);
			if (x == 1)
				merge(i, j);
		}
	}
	for (int i = 1; i <= m; i++)
		scanf("%d", &trip[i]);
	for (int i = 1; i <= m; i++)
		for (int j = i + 1; j <= m; j++)
			if (find(trip[i]) != find(trip[j]))
				flag = 0;
	if (flag == 0)
		printf("NO");
	else
		printf("YES");
}
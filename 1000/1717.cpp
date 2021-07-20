#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000001

int par[MAX];

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
	int n, m;
	scanf("%d%d", &n, &m);
	memset(par, -1, sizeof(par));
	while (m--)
	{
		int x, a, b;
		scanf("%d%d%d", &x, &a, &b);
		if (x == 0)
			merge(a, b);
		else
		{
			if (find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}
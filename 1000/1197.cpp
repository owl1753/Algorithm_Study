#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10001

struct adj
{
	int a, b, c;
};

int par[MAX];
int V, E, result = 0;
vector<adj> v;

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

bool compare(adj a, adj b)
{
	return a.c < b.c;
}

int main()
{
	memset(par, -1, sizeof(par));
	scanf("%d%d", &V, &E);
	for (int i = 1; i <= E; i++)
	{
		adj temp;
		scanf("%d%d%d", &temp.a, &temp.b, &temp.c);
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
	{
		if (find(v[i].a) == find(v[i].b))
			continue;
		merge(v[i].a, v[i].b);
		result += v[i].c;
	}
	printf("%d", result);
}
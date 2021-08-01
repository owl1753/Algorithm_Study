#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 100001

vector<int> adj[MAX];
int visited[MAX];
int height[MAX];
int par[MAX][17];
int n, m;

void dfs(int cur, int h)
{
	visited[cur] = 1;
	height[cur] = h;
	for (int i = 0; i < adj[cur].size(); i++)
	{
		int next = adj[cur][i];
		if (visited[next] == 0)
		{
			par[next][0] = cur;
			dfs(next, h + 1);
		}
	}
}

int lca(int u, int v)
{
	int result = 0;
	int diff = height[u] - height[v];
	for (int i = 0; diff; i++)
	{
		if (diff % 2)
			u = par[u][i];
		diff /= 2;
	}
	if (u == v)
		result = u;
	else
	{
		for (int i = 16; i >= 0; i--)
		{
			if (par[u][i] != par[v][i])
			{
				u = par[u][i];
				v = par[v][i];
			}
		}
		result = par[u][0];
	}
	return result;
}

int main()
{
	memset(par, -1, sizeof(par));
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	for (int i = 1; i < 17; i++)
		for (int j = 1; j <= n; j++)
			if (par[j][i - 1] != -1)
				par[j][i] = par[par[j][i - 1]][i - 1];
	scanf("%d", &m);
	while (m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if (height[u] < height[v])
			swap(u, v);
		printf("%d\n", lca(u, v));
	}
}
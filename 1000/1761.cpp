#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 40001

vector<pair<int, int>> adj[MAX];
int visited[MAX];
int height[MAX];
int dist[MAX];
int par[MAX][16];
int n, m;

void dfs(int cur, int h, int dis)
{
	visited[cur] = 1;
	height[cur] = h;
	for (int i = 0; i < adj[cur].size(); i++)
	{
		int next = adj[cur][i].first;
		if (visited[next] == 0)
		{
			par[next][0] = cur;
			dist[next] = dis + adj[cur][i].second;
			dfs(next, h + 1, dist[next]);
		}
	}
}

int lca(int u, int v)
{
	int w;
	int diff = height[u] - height[v];
	for (int i = 0; diff; i++)
	{
		if (diff % 2)
			u = par[u][i];
		diff /= 2;
	}
	if (u == v)
		w = u;
	else
	{
		for (int i = 15; i >= 0; i--)
		{
			if (par[u][i] != par[v][i])
			{
				u = par[u][i];
				v = par[v][i];
			}
		}
		w = par[u][0];
	}
	return w;
}

int main()
{
	memset(par, -1, sizeof(par));
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	dfs(1, 1, 0);
	for (int i = 1; i < 16; i++)
		for (int j = 1; j <= n; j++)
			if (par[j][i - 1] != -1)
				par[j][i] = par[par[j][i - 1]][i - 1];
	scanf("%d", &m);
	while (m--)
	{
		int u, w, v, result;
		scanf("%d%d", &u, &v);
		if (height[u] < height[v])
			swap(u, v);
		w = lca(u, v);
		result = (dist[u] - dist[w]) + (dist[v] - dist[w]);
		printf("%d\n", result);
	}
}
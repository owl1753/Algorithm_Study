#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define MAX 50001

vector<int> adj[MAX];
int visited[MAX];
int height[MAX];
int par[MAX];
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
			par[next] = cur;
			dfs(next, h + 1);
		}
	}
}

int lca(int u, int v)
{
	int result = 0;
	while (1)
	{
		if (height[u] < height[v])
			v = par[v];
		else if (height[u] > height[v])
			u = par[u];
		else
		{
			if (u == v)
			{
				result = u;
				break;
			}
			else
			{
				v = par[v];
				u = par[u];
			}
		}

	}
	return result;
}

int main()
{
	memset(par, -1, sizeof(par));
	scanf("%d", &n);
	for (int i = 1; i < n ; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	scanf("%d", &m);
	while (m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", lca(u, v));
	}
}
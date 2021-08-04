#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 3001

vector<int> adj[MAX];
queue<int> q;
int visited[MAX];
int finished[MAX];
int dist[MAX];
int check[MAX];
int cycle = 0;

void dfs(int here, int last)
{
	visited[here] = 1;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int next = adj[here][i];
		if (visited[next] == 0)
			dfs(next, here);
		if (finished[next] == 0 && next != last)
		{
			cycle = 1;
			check[here] = 1;
			check[next] = 1;
			finished[here] = 1;
			return;
		}
		else if (check[here] == 1)
			cycle = 0;
		else if (cycle == 1)
		{
			check[here] = 1;
			finished[here] = 1;
			return;
		}
	}
	finished[here] = 1;
}

int bfs(int start)
{
	q.push(start);
	dist[start] = 0;
	while (q.size() != NULL)
	{
		int here = q.front();
		q.pop();
		if (check[here] == 1)
		{
			return dist[here];
		}
		for (int i = 0; i < adj[here].size(); i++)
		{
			int next = adj[here][i];
			if (dist[next] == -1)
			{
				q.push(next);
				dist[next] = dist[here] + 1;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (visited[i] == 0)
			dfs(i, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			dist[j] = -1;
		while (q.size() != NULL)
			q.pop();
		cout << bfs(i) << " ";
	}
}
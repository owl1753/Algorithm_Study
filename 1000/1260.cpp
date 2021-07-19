#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001] = { 0 };
int dvisited[1001] = { 0 };
int bvisited[1001] = { 0 };
queue<int> q;

void dfs(int n, int v)
{
	if (dvisited[v] == 1)
	{
		return;
	}
	dvisited[v] = 1;
	cout << v << " ";
	for (int i = 1; i <= n; i++)
	{
		if (graph[v][i] == 1)
		{
			dfs(n, i);
		}
	}
}

void bfs(int n, int v)
{
	while (q.size() != NULL)
	{
		v = q.front();
		if (bvisited[v] != 1)
		{
			cout << v << " ";
		}
		bvisited[v] = 1;
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (graph[v][i] == 1 && bvisited[i] != 1)
			{
				q.push(i);
			}
		}
	}
}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}
	dfs(n, v);
	cout << "\n";
	q.push(v);
	bfs(n, v);

	return 0;
}
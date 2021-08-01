#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[1001];
queue<int> q;
int visited[1001] = { 0 };

int bfs(int n)
{
	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (visited[i] == 0)
		{
			cnt++;
			q.push(i);
			visited[i] = 1;
		}
		while (q.size() != NULL)
		{
			
			int here = q.front();
			q.pop();
			for (int j = 0; j < graph[here].size(); j++)
			{
				int there = graph[here][j];
				if (visited[there] == 0)
				{
					visited[there] = 1;
					q.push(there);
				}
			}
		}
	}
	return cnt;
}

int main()
{

	int n, m, max = 0;
	cin >> n >> m;
	n++;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout << bfs(n);
}
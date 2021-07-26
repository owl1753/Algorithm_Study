#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101

vector<int> adj[MAX];
int dist[MAX];
queue<int> q;

int main()
{
	int n, m, start, end;
	cin >> n;
	cin >> start >> end;
	cin >> m;
	for (int i = 1; i <= n; i++)
		dist[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	q.push(start);
	dist[start] = 0;
	while (q.size() != NULL)
	{
		int here = q.front();
		q.pop();
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
	cout << dist[end];
}
#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1987654321

vector<pair<int, int>> adj[1001];
vector<int> order[1001];
priority_queue<pair<int, int>> pq;
int dist[1001];

int main()
{
	int n, m, start, end;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back(make_pair(y, z));
	}
	cin >> start >> end;
	for (int i = 1; i <= n; i++)
		dist[i] = MAX;
	dist[start] = 0;
	pq.push(make_pair(0, start));
	order[start].push_back(start);
	while (pq.size() != NULL)
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[here] < cost)
			continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int next = adj[here][i].first;
			int add = adj[here][i].second + cost;
			if (add < dist[next])
			{
				dist[next] = add;
				pq.push(make_pair(-add, next));
				order[next].erase(order[next].begin(), order[next].end());
				for (int j = 0; j < order[here].size(); j++)
					order[next].push_back(order[here][j]);
				order[next].push_back(next);
			}
		}
	}
	cout << dist[end] << "\n";
	cout << order[end].size() << "\n";
	for (int i = 0; i < order[end].size(); i++)
		cout << order[end][i] << " ";
}
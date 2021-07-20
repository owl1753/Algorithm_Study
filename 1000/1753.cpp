#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1987654321

vector<pair<int, int>> adj[20001];
priority_queue<pair<int, int>> pq;
int dist[20001];

int main()
{
	int V, E, start;
	cin >> V >> E;
	cin >> start;
	for (int i = 1; i <= E; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back(make_pair(y, z));
	}
	for (int i = 1; i <= V; i++)
		dist[i] = MAX;
	dist[start] = 0;
	pq.push(make_pair(0, start));
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
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == MAX)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}
#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1987654321

vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>> pq;
int dist[1001][1001];

int main()
{
	int N, M, X, max = 0;
	cin >> N >> M >> X;
	for (int i = 1; i <= M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back(make_pair(y, z));
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = MAX;
	for (int i = 1; i <= N; i++)
	{
		pq.push(make_pair(0, i));
		dist[i][i] = 0;
		while (pq.size() != NULL)
		{
			int here = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();
			if (dist[i][here] < cost)
				continue;
			for (int j = 0; j < adj[here].size(); j++)
			{
				int next = adj[here][j].first;
				int add = adj[here][j].second + cost;
				if (add < dist[i][next])
				{
					dist[i][next] = add;
					pq.push(make_pair(-add, next));
				}
			}
		}
	}
	for (int i = 2; i <= N; i++)
		if (max < dist[i][X] + dist[X][i])
			max = dist[i][X] + dist[X][i];
	cout << max;
}
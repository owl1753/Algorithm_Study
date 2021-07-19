#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 810
#define INF 987654321

vector<pair<int, int>> adj[MAX];
int dist_s[MAX];
int dist_v1[MAX];
int dist_v2[MAX];
int N, E, v1, v2, route1 = 0, route2 = 0, result = 0, flag1 = 1, flag2 = 1;

void dijkstra(int start, int dist[])
{
	priority_queue<pair<int, int>> pq;
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
			int there = adj[here][i].first;
			int add = adj[here][i].second;
			if (cost + add < dist[there])
			{
				dist[there] = cost + add;
				pq.push(make_pair(-dist[there], there));
			}
		}
	}
}

int main()
{
	scanf("%d%d", &N, &E);
	for (int i = 1; i <= E; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	scanf("%d%d", &v1, &v2);
	for (int i = 1; i <= N; i++)
	{
		dist_s[i] = INF;
		dist_v1[i] = INF;
		dist_v2[i] = INF;
	}
	dijkstra(1, dist_s);
	if (dist_s[v1] == INF)
		flag1 = 0;
	if (dist_s[v2] == INF)
		flag2 = 0;
	dijkstra(v1, dist_v1);
	if (dist_v1[v2] == INF)
		flag1 = 0;
	if (dist_v1[N] == INF)
		flag2 = 0;
	dijkstra(v2, dist_v2);
	if (dist_v2[N] == INF)
		flag1 = 0;
	if (dist_v2[v1] == INF)
		flag2 = 0;
	route1 = dist_s[v1] + dist_v1[v2] + dist_v2[N];
	route2 = dist_s[v2] + dist_v2[v1] + dist_v1[N];
	result = min(route1, route2);
	if (flag1 == 0 && flag2 == 0)
		printf("-1");
	else
		printf("%d", result);
}
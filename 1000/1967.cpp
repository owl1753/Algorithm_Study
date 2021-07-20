#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

vector<pair<int, int>> adj[10001];
int dist[10001];
int n, maxx = 0;

void dfs(int cur) {
	if (dist[cur] > maxx)
		maxx = dist[cur];
	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur][i].first;
		int add = adj[cur][i].second;
		if (dist[next] != -1)
			continue;
		dist[next] = dist[cur] + add;
		dfs(next);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	for (int i = 1; i <= n; i++) {
		memset(dist, -1, sizeof(dist));
		dist[i] = 0;
		dfs(i);
	}
	printf("%d", maxx);
}
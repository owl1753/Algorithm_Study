#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[101];
int minn = 987654321;
int answer;

void bfs(int start, int* dist) {
	queue<int> q;
	dist[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			if (dist[next] == -1) {
				dist[next] = dist[here] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		int dist[101];
		int sum = 0;
		memset(dist, -1, sizeof(dist));
		bfs(i, dist);
		for (int i = 1; i <= n; i++) {
			if (dist[i] >= 0)
				sum += dist[i];
		}
		if (minn > sum) {
			minn = sum;
			answer = i;
		}

	}
	printf("%d", answer);
}
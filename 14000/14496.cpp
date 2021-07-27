#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

vector<int> adj[2001];
queue<int> q;
int dist[2001];
int n, m, a, b;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dist, -1, sizeof(dist));
	cin >> a >> b;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);

	}
	dist[a] = 0;
	q.push(a);
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
	cout << dist[b];
}
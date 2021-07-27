#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define INF 987654321

int map[135][135];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 ,0 };
int n;

int dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;
	int dist[135][135];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;
	pq.push(make_pair(-map[1][1], make_pair(1, 1)));
	dist[1][1] = map[1][1];
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int hcost = -pq.top().first;
		pq.pop();
		if (hcost > dist[x][y])
			continue;
		for (int i = 0; i < 4; i++) {
			int px = x + dx[i];
			int py = y + dy[i];
			if (1 <= px && 1 <= py && px <= n && py <= n) {
				int ncost = hcost + map[px][py];
				if (dist[px][py] > ncost) {
					pq.push(make_pair(-ncost, make_pair(px, py)));
					dist[px][py] = ncost;
				}
			}
		}
	}
	return dist[n][n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int cnt = 1;
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];
		cout << "Problem " << cnt << ": " << dijkstra() << "\n";
		cnt++;
	}
}
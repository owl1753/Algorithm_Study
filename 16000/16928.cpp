#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int, pair<int, int>>> q;
int dist[101][16][16];
int ledder[101];
int snake[101];
int n, m, answer = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dist, -1, sizeof(dist));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		ledder[a] = b;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		snake[a] = b;
	}
	dist[1][0][0] = 0;
	q.push(make_pair(1, make_pair(0, 0)));
	while (!q.empty()) {
		int here = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (here == 100)
			break;

		for (int i = 1; i <= 6; i++) {
			int next, xp = 0, yp = 0;
			if (here + i > 100)
				continue;
			if (ledder[here + i] != 0) {
				next = ledder[here + i];
				xp++;
			}
			else if (snake[here + i] != 0) {
				next = snake[here + i];
				yp++;
			}
			else
				next = here + i;
			if (dist[next][x + xp][y + yp] == -1) {
				dist[next][x + xp][y + yp] = dist[here][x][y] + 1;
				q.push(make_pair(next, make_pair(x + xp, y + yp)));
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (answer > dist[100][i][j] && dist[100][i][j] != -1)
				answer = dist[100][i][j];
		}
	}
	cout << answer;
}
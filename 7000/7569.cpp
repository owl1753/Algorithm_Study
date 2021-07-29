#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct Triple {
	int x, y, z;
};

queue<Triple> q;
int map[101][101][101];
int dist[101][101][101];
int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int n, m, h, result = 0, flag = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dist, -1, sizeof(dist));
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({ j, k, i });
					dist[i][j][k] = 0;
				}
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int px = x + dx[i];
			int py = y + dy[i];
			int pz = z + dz[i];
			if (0 <= px && 0 <= py && 0 <= pz && px < n && py < m && pz < h) {
				if (dist[pz][px][py] == -1 && map[pz][px][py] == 0) {
					map[pz][px][py] = 1;
					dist[pz][px][py] = dist[z][x][y] + 1;
					q.push({ px, py, pz });
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (result < dist[i][j][k])
					result = dist[i][j][k];
				if (map[i][j][k] == 0)
					flag = 0;
			}
		}
	}
	if (flag == 0)
		result = -1;
	cout << result;
}
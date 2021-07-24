#include <iostream>
#include <queue>
using namespace std;
#define MAX 101

int map[MAX][MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n, k = 0, result = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (k < map[i][j])
				k = map[i][j];
		}
	}
	while (k--) {
		int visited[MAX][MAX];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				visited[i][j] = 0;
			}
		}
		queue<pair<int, int>> q;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > k && visited[i][j] == 0) {
					visited[i][j] = 0;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int i = 0; i < 4; i++) {
							int px = x + dx[i];
							int py = y + dy[i];
							if (0 < px && 0 < py && px <= n && py <= n) {
								if ((map[px][py] > k) && visited[px][py] == 0) {
									visited[px][py] = 1;
									q.push(make_pair(px, py));
								}
							}
						}
					}
					cnt++;
				}
			}
		}
		if (result < cnt)
			result = cnt;
	}
	printf("%d", result);
}
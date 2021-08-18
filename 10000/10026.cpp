#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
char map[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int visited1[101][101], visited2[101][101];
int n, result1 = 0, result2 = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited1[i][j] == 0) {
				visited1[i][j] = 1;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int px = x + dx[i];
						int py = y + dy[i];
						if (0 <= px && 0 <= py && px < n && py < n) {
							if (visited1[px][py] == 0 && map[x][y] == map[px][py]) {
								visited1[px][py] = 1;
								q.push(make_pair(px, py));
							}
						}
					}
				}
				result1++;
			}
			if (visited2[i][j] == 0) {
				visited2[i][j] = 1;
				q.push(make_pair(i, j));
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int px = x + dx[i];
						int py = y + dy[i];
						if (0 <= px && 0 <= py && px < n && py < n) {
							if (visited2[px][py] == 0 && (map[x][y] == map[px][py] || (map[x][y] == 'R' && map[px][py] == 'G') || (map[x][y] == 'G' && map[px][py] == 'R'))) {
								visited2[px][py] = 1;
								q.push(make_pair(px, py));
							}
						}
					}
				}
				result2++;
			}
		}
	}
	cout << result1 << " " << result2;
}
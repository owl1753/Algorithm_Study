#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAX 987654321

pair<int, int> start;
int map[21][21];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, answer = 0, weight = 2, cnt = 0;

pair<int, int> bfs() {
    int dist[21][21];
    queue<pair<int, int>> q;
    pair<int, int> able;
    memset(dist, -1, sizeof(dist));
    able = make_pair(MAX, MAX);
    dist[start.first][start.second] = 0;
    q.push(start);
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (1 <= map[x][y] && map[x][y] <= 6) {
            if (weight > map[x][y]) {
                if (able == make_pair(MAX, MAX) || dist[able.first][able.second] > dist[x][y]) {
                    able = make_pair(x, y);
                }
                else if (dist[able.first][able.second] == dist[x][y]) {
                    if (able.first > x)
                        able = make_pair(x, y);
                    else if (able.first == x) {
                        if (able.second > y)
                            able = make_pair(x, y);
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int px = x + dx[i];
            int py = y + dy[i];
            if (0 < px && 0 < py && px <= n && py <= n) {
                if (dist[px][py] == -1 && weight >= map[px][py]) {
                    dist[px][py] = dist[x][y] + 1;
                    q.push(make_pair(px, py));
                }
            }
        }
    }
    if (able != make_pair(MAX, MAX))
        answer += dist[able.first][able.second];
    return able;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                start = make_pair(i, j);
                map[i][j] = 0;
            }
                
        }
    }

    while (1) {
        pair<int, int> able;
        able = bfs();
        if (able == make_pair(MAX, MAX))
            break;
        start = able;
        map[able.first][able.second] = 0;
        cnt++;
        if (cnt == weight) {
            weight++;
            cnt = 0;
        }
    }

    cout << answer;
}
#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1001

queue<pair<pair<int, int>, int>> q;
int dist[MAX][MAX][2];
char map[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &map[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k <= 1; k++)
				dist[i][j][k] = -1;
	q.push(make_pair(make_pair(0, 0), 0));
	dist[0][0][0] = 1;
	while (q.size() != NULL)
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int px = x + dx[i];
			int py = y + dy[i];
			if (0 <= px && 0 <= py && px < n && py < m)
			{
				if (map[px][py] == '1' && wall == 0 && dist[px][py][1] == -1)
				{
					dist[px][py][wall + 1] = dist[x][y][wall] + 1;
					q.push(make_pair(make_pair(px, py), wall + 1));
				}
				if (map[px][py] == '0' && dist[px][py][wall] == -1)
				{
					dist[px][py][wall] = dist[x][y][wall] + 1;
					q.push(make_pair(make_pair(px, py), wall));
				}
			}
		}
	}
	if (dist[n - 1][m - 1][0] == -1)
		printf("%d", dist[n - 1][m - 1][1]);
	else if (dist[n - 1][m - 1][1] == -1)
		printf("%d", dist[n - 1][m - 1][0]);
	else
		printf("%d", min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]));
}
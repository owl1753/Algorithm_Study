#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAX 51

char map[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m, result = 0;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &map[i][j]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			queue<pair<int, int>> q;
			int dist[MAX][MAX];
			memset(dist, -1, sizeof(dist));
			if (map[i][j] != 'L')
				continue;
			q.push(make_pair(i, j));
			dist[i][j] = 0;
			while (q.size() != NULL)
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int px = x + dx[i];
					int py = y + dy[i];
					if (0 <= px && 0 <= py && px < n && py < m)
					{
						if (dist[px][py] == -1 && map[px][py] == 'L')
						{
							q.push(make_pair(px, py));
							dist[px][py] = dist[x][y] + 1;
							if (dist[px][py] > result)
								result = dist[px][py];
						}
					}
				}
			}
		}
	}
	printf("%d", result);
}
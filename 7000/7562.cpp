#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAX 300 + 10

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int map[MAX][MAX] = { 0, };
		int dist[MAX][MAX];
		queue<pair<int, int>> q;
		int l, sx, sy, ex, ey;
		memset(dist, -1, sizeof(dist));
		scanf("%d", &l);
		scanf("%d%d", &sx, &sy);
		scanf("%d%d", &ex, &ey);
		dist[sx][sy] = 0;
		q.push(make_pair(sx, sy));
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++)
			{
				int px = x + dx[i];
				int py = y + dy[i];
				if (0 <= px && 0 <= py && px < l && py < l)
				{
					if (dist[px][py] == -1)
					{
						dist[px][py] = dist[x][y] + 1;
						q.push(make_pair(px, py));
					}
				}
			}
		}
		printf("%d\n", dist[ex][ey]);
	}
}
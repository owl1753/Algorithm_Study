#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
#define MAX 51

int main()
{
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int map[MAX][MAX] = { 0 };
		int visited[MAX][MAX] = { 0 };
		int n, m, k, cnt = 0;
		scanf("%d%d%d", &m, &n, &k);
		for (int i = 0; i < k; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			map[y][x] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == 0)
				{
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					visited[i][j] = 1;
					cnt++;
					while (q.size() != NULL)
					{
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						for (int i = 0; i < 4; i++)
						{
							int px = dx[i] + x;
							int py = dy[i] + y;
							if (0 <= px && 0 <= py && px < m && py < n)
							{
								if (map[py][px] == 1 && visited[py][px] == 0)
								{
									visited[py][px] = 1;
									q.push(make_pair(py, px));
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
}
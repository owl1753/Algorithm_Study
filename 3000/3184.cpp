#pragma warning(disable:4996)
#include <iostream>
#include <queue>
using namespace std;
#define MAX 250

char map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };
int R, C, cnt1 = 0, cnt2 = 0;

int main()
{
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'o')
				cnt1++;
			if (map[i][j] == 'v')
				cnt2++;
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			queue<pair<int, int>> q;
			int scnt1 = 0, scnt2 = 0;
			if (map[i][j] != '#' && visited[i][j] == 0)
			{
				q.push(make_pair(i, j));
				visited[i][j] = 1;
				while (q.size() != NULL)
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					if (map[x][y] == 'o')
						scnt1++;
					if (map[x][y] == 'v')
						scnt2++;
					for (int i = 0; i < 4; i++)
					{
						int px = x + dx[i];
						int py = y + dy[i];
						if (0 <= px && 0 <= py && px <= R && py <= C)
						{
							if (visited[px][py] == 0 && map[px][py] != '#')
							{
								q.push(make_pair(px, py));
								visited[px][py] = 1;
							}
						}
					}
				}
				if (scnt1 > scnt2)
					cnt2 -= scnt2;
				else
					cnt1 -= scnt1;
			}
		}
	}
	printf("%d %d", cnt1, cnt2);
}
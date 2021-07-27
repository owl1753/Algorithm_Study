#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<pair<int, int>> q;

	int dx[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
	int dy[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };

	while (1)
	{
		int map[60][60];
		int visited[60][60] = { 0 };
		int w, h, cnt = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == 0)
				{
					visited[i][j] = 1;
					q.push(make_pair(i, j));
					cnt++;
				}
				while (q.size() != NULL)
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 8; i++)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (1 <= nx && 1 <= ny && nx <= h && ny <= w)
						{
							if (map[nx][ny] == 1 && visited[nx][ny] == 0)
							{
								q.push(make_pair(nx, ny));
								visited[nx][ny] = 1;
							}
						}
					}
				}
			}
		}
		cout << cnt << "\n";
	}
}
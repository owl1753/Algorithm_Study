#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<pair<int, int>> q;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	char map[301][301];
	int n, m, x1, y1, x2, y2, cnt = 0, flag = 0;
	cin >> n >> m;
	cin >> x1 >> y1 >> x2 >> y2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	x1--;
	y1--;
	x2--;
	y2--;
	while (1)
	{
		int visited[301][301] = { 0 };
		q.push(make_pair(x1, y1));
		visited[x1][y1] = 1;
		while (q.size() != NULL)
		{
			pair<int, int> tmp = q.front();
			int x = tmp.first;
			int y = tmp.second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int px = x + dx[i];
				int py = y + dy[i];
				if (0 <= px && 0 <= py && px < n && py < m && visited[px][py] == 0)
				{
					if (map[px][py] == '0')
					{
						q.push(make_pair(px, py));
						visited[px][py] = 1;

					}
					else if (map[px][py] == '1')
					{
						map[px][py] = '0';
						visited[px][py] = 1;
					}
					else if (map[px][py] == '#')
					{
						flag = 1;
						break;
					}
				}
			}
		}
		cnt++;
		if (flag == 1)
			break;
	}
	cout << cnt;
}
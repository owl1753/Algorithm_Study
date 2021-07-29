#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1010

queue<pair<pair<int, int>, int>> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int toma[MAX][MAX];

int main()
{
	int n, m, cnt = 0, flag = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> toma[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (toma[i][j] == 1)
			{
				q.push(make_pair(make_pair(i, j), cnt));
			}
		}
	}
	while (q.size() != 0)
	{
		pair<int, int> tmp = q.front().first;
		int x = tmp.first;
		int y = tmp.second;
		cnt = q.front().second;
		q.pop();
		for (int j = 0; j < 4; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (0 <= nx && 0 <= ny && nx < n && ny < m)
			{
				if (toma[nx][ny] == 0)
				{
					q.push(make_pair(make_pair(nx, ny), cnt + 1));
					toma[nx][ny] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (toma[i][j] == 0)
			{
				flag = 1;
			}
		}
	}
	if (flag == 1)
		cout << -1;
	else
		cout << cnt;
}
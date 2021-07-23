#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	queue<pair<pair<int, int>, int>> q;
	char map[101][101];
	int visited[100][100] = { 0 };
	int n, m, x = 0, y = 0, cnt = 1;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", map[i]);
	}
	q.push(make_pair(make_pair(x, y), cnt));
	while (q.size() != NULL)
	{
		if (x + 1 == n && y + 1 == m)
		{
			break;
		}
		pair<pair<int, int>, int> tmp = q.front();
		x = tmp.first.first;
		y = tmp.first.second;
		cnt = tmp.second;
		q.pop();
		if (map[x + 1][y] == '1' && visited[x + 1][y] == 0)
		{
			q.push(make_pair(make_pair(x + 1, y), cnt + 1));
			visited[x + 1][y] = 1;
		}
		if (map[x - 1][y] == '1' && visited[x - 1][y] == 0)
		{
			q.push(make_pair(make_pair(x - 1, y), cnt + 1));
			visited[x - 1][y] = 1;
		}
		if (map[x][y + 1] == '1' && visited[x][y + 1] == 0)
		{
			q.push(make_pair(make_pair(x, y + 1), cnt + 1));
			visited[x][y + 1] = 1;
		}
		if (map[x][y - 1] == '1' && visited[x][y - 1] == 0)
		{
			q.push(make_pair(make_pair(x, y - 1), cnt + 1));
			visited[x][y - 1] = 1;
		}
	}
	printf("%d", cnt);
}
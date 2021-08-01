#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

char map[MAX][MAX];
int dist[MAX][MAX][11];
queue<pair<pair<int, int>, int>> q;

int main()
{
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };
	int N, M, K, min;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k <= 10; k++)
				dist[i][j][k] = -1;
	if (map[0][0] == '0')
	{
		q.push(make_pair(make_pair(0, 0), 0));
		dist[0][0][0] = 1;
	}
	else
	{
		q.push(make_pair(make_pair(0, 0), 1));
		dist[0][0][1] = 1;
	}
	while (q.size() != NULL)
	{
		pair<int, int> tmp = q.front().first;
		int x = tmp.first;
		int y = tmp.second;
		int cnt = q.front().second;
		int min;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int px = x + dx[i];
			int py = y + dy[i];
			if (0 <= px && px < N && 0 <= py && py < M)
			{
				if (map[px][py] == '0' && dist[px][py][cnt] == -1)
				{
					q.push(make_pair(make_pair(px, py), cnt));
						dist[px][py][cnt] = dist[x][y][cnt] + 1;
				}
				else if (map[px][py] == '1' && cnt < K && dist[px][py][cnt + 1] == -1)
				{
					q.push(make_pair(make_pair(px, py), cnt + 1));
						dist[px][py][cnt + 1] = dist[x][y][cnt] + 1;
				}
			}
		}
	}
	min = dist[N - 1][M - 1][0];
	for (int i = 0; i <= 10; i++)
	{
		if ((min == -1 || dist[N-1][M-1][i] < min) && dist[N-1][M-1][i] != -1)
		{
			min = dist[N - 1][M - 1][i];
		}
	}
	cout << min;
}
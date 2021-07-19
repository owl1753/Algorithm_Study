#pragma warning(disable:4996)
#include <iostream>
#include <queue>
using namespace std;
#define MAX 110
#define INF 987654321

priority_queue<pair<int, pair<int, int>>> pq;
char map[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int N, M;

int main()
{
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf(" %c", &map[i][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dist[i][j] = INF;
	pq.push(make_pair(0, make_pair(0, 0)));
	dist[0][0] = 0;
	while (pq.size() != NULL)
	{
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (dist[x][y] < cost)
			continue;
		for (int i = 0; i < 4; i++)
		{
			int px = x + dx[i];
			int py = y + dy[i];
			if (0 <= px && 0 <= py && px < N && py < M)
			{
				int add = map[px][py] - '0';
				if (cost + add < dist[px][py])
				{
					dist[px][py] = cost + add;
					pq.push(make_pair(-dist[px][py], make_pair(px, py)));
				}
			}
		}
	}
	printf("%d", dist[N - 1][M - 1]);
}
#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 101

vector<pair<int, int>> adj[MAX];
queue<int> q;
int dp[MAX][MAX];
int indegree[MAX];
int N, M;

int main()
{
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++)
	{
		int X, Y, K;
		scanf("%d%d%d", &X, &Y, &K);
		adj[Y].push_back(make_pair(X, K));
		indegree[X]++;
	}
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			dp[i][i] = 1;
		}
	}

	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int next = adj[here][i].first;
			indegree[next]--;
			for (int j = 1; j <= N; j++)
				dp[next][j] += dp[here][j] * adj[here][i].second;
			if (indegree[next] == 0)
				q.push(next);
		}
	}
	for (int i = 1; i < N; i++)
		if (dp[N][i] != 0)
			printf("%d %d\n", i, dp[N][i]);
}
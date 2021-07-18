#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
#include <limits.h>
using namespace std;
#define MAX 1001

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		vector<int> adj[MAX];
		queue<int> q;
		int indegree[MAX];
		int time[MAX];
		int dp[MAX];
		int N, K, W, result = 0;
		memset(indegree, 0, sizeof(indegree));
		memset(dp, 0, sizeof(dp));
		scanf("%d%d", &N, &K);
		for (int i = 1; i <= N; i++)
			scanf("%d", &time[i]);
		for (int i = 1; i <= K; i++)
		{
			int X, Y;
			scanf("%d%d", &X, &Y);
			adj[X].push_back(Y);
			indegree[Y]++;
		}
		scanf("%d", &W);
		for (int i = 1; i <= N; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
				dp[i] = time[i];
			}
		}
		while (q.size() != NULL)
		{
			int here = q.front();
			q.pop();
			for (int i = 0; i < adj[here].size(); i++)
			{
				int next = adj[here][i];
				indegree[next]--;
				dp[next] = max(dp[here] + time[next], dp[next]);
				if (indegree[next] == 0)
					q.push(next);
			}
		}
		printf("%d\n", dp[W]);
	}
}
#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
#define MAX 501

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		vector<int> adj[MAX];
		queue<int> q;
		vector<int> result;
		int team[MAX];
		int indegree[MAX];
		int n, m, flag = 0;
		memset(indegree, 0, sizeof(indegree));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &team[i]);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				adj[team[i]].push_back(team[j]);
				indegree[team[j]]++;
			}
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
		{
			int mflag = 0;
			int a, b;
			scanf("%d%d", &a, &b);
			for (int j = 0; j < adj[a].size(); j++)
			{
				if (adj[a][j] == b)
				{
					adj[a].erase(adj[a].begin() + j);
					adj[b].push_back(a);
					indegree[b]--;
					indegree[a]++;
					mflag = 1;
				}
			}
			if (mflag == 0)
			{
				for (int j = 0; j < adj[b].size(); j++)
				{
					if (adj[b][j] == a)
					{
						adj[b].erase(adj[b].begin() + j);
						adj[a].push_back(b);
						indegree[a]--;
						indegree[b]++;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
			if (indegree[i] == 0)
				q.push(i);
		while (!q.empty())
		{
			int here = q.front();
			q.pop();
			result.push_back(here);
			for (int i = 0; i < adj[here].size(); i++)
			{
				int next = adj[here][i];
				indegree[next]--;
				if (indegree[next] == 0)
					q.push(next);
				if (q.size() >= 2)
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0)
		{
			if (result.size() == n)
				for (int i = 0; i < n; i++)
					printf("%d ", result[i]);
			else
				printf("IMPOSSIBLE");
		}
		else
			printf("?");
		printf("\n");
	}
}
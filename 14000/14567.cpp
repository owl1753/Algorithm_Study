#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
#define MAX 1001

vector<int> adj[MAX];
queue<int> q;
int dist[MAX];
int indegree[MAX];
int N, M;

int main()
{
	memset(dist, -1, sizeof(dist));
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		int A, B;
		scanf("%d%d", &A, &B);
		adj[A].push_back(B);
		indegree[B]++;
	}
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			dist[i] = 1;
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
			if (indegree[next] == 0)
			{
				q.push(next);
				dist[next] = dist[here] + 1;
			}
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", dist[i]);
}
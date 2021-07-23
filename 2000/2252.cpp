#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 32001

vector<int> adj[MAX];
vector<int> result;
queue<int> q;
int indegree[MAX];
int N, M;

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		int A, B;
		scanf("%d%d", &A, &B);
		adj[A].push_back(B);
		indegree[B]++;
	}
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
			q.push(i);
	while (q.size() != NULL)
	{
		int here = q.front();
		result.push_back(here);
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int next = adj[here][i];
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}
	for (int i = 0; i < result.size(); i++)
		printf("%d ", result[i]);
}
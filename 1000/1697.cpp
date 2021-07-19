#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

queue<int> q;
vector<int> adj[MAX];
int dist[MAX];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < MAX; i++)
		dist[i] = -1;
	for (int i = 0; i < MAX; i++)
	{
		if (i != 0)
			adj[i].push_back(i - 1);
		if (i != (MAX - 1))
			adj[i].push_back(i + 1);
		if (i * 2 <= (MAX - 1))
			adj[i].push_back(i * 2);
	}
	q.push(n);
	dist[n] = 0;
	while (q.size() != NULL)
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int next = adj[here][i];
			if (dist[next] == -1)
			{
				dist[next] = dist[here] + 1;
				q.push(next);
			}
		}
	}
	cout << dist[k];
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<int> answer;
vector<int> adj[33333];
int indegree[33333];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			pq.push(i);
	while (!pq.empty()) {
		int here = pq.top();
		pq.pop();
		answer.push_back(here);
		
		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			indegree[next]--;

			if (indegree[next] == 0) pq.push(next);
		}
	}
	for (int i = 0; i < answer.size(); i++) cout << answer[i] << " ";
}
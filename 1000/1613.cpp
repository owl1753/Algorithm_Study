#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define MAX 410

vector<int> adj[MAX];
int check[MAX][MAX];
int n, k, s;

void dfs(int start, int cur, int* visited) {
	visited[cur] = 1;
	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur][i];
		if (visited[next] == 0) {
			check[start][next] = 1;
			dfs(start, next, visited);
		}
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		int visited[MAX];
		memset(visited, 0, sizeof(visited));
		dfs(i, i, visited);
	}
	scanf("%d", &s);
	while (s--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (check[a][b])
			printf("-1\n");
		else if (check[b][a])
			printf("1\n");
		else
			printf("0\n");
	}
}
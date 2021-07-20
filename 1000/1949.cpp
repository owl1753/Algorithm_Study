#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10001

vector<int> adj[MAX];
int dp[MAX][2];
int visited[MAX];
int w[MAX];
int n;

void func(int cur) {
	visited[cur] = 1;
	dp[cur][0] = w[cur];
	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur][i];
		if (visited[next] == 0) {
			func(next);
			dp[cur][0] += dp[next][1];
			dp[cur][1] += max(dp[next][0], dp[next][1]);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	func(1);
	printf("%d", max(dp[1][0], dp[1][1]));
}
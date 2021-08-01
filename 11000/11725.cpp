#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
int visited[100001];
int result[100001];
int n;

void dfs(int cur) {
	visited[cur] = 1;
	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur][i];
		if (visited[next] == 0) {
			result[next] = cur;
			dfs(next);
		}
	}
}1

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << result[i] << "\n";
	}
}
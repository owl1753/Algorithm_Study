#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[100001];
vector<pair<int, int>> arr[100001];
int v, result = 0;

int dfs(int here) {
	visited[here] = true;

	vector<int> tmp;

	for (int i = 0; i < arr[here].size(); i++) {
		int next = arr[here][i].first;
		int cost = arr[here][i].second;

		if (visited[next]) continue;

		tmp.push_back(cost + dfs(next));
	}

	if (tmp.empty()) return 0;

	if (tmp.size() == 1) {
		result = max(result, tmp[0]);
		return tmp[0];
	}
	
	sort(tmp.begin(), tmp.end());

	result = max(result, tmp[tmp.size() - 1] + tmp[tmp.size() - 2]);
	return tmp[tmp.size() - 1];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> v;
	for (int i = 1; i <= v; i++) {
		int n;
		cin >> n;
		while (true) {
			pair<int, int> tmp;
			cin >> tmp.first;
			if (tmp.first == -1) break;
			cin >> tmp.second;
			arr[n].push_back(tmp);
		}
	}
	dfs(1);
	cout << result;
}
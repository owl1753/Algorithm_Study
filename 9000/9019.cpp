#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		bool visited[10001];
		string result;
		queue<pair<int, string>> q;
		int start, goal;
		cin >> start >> goal;
		for (int i = 0; i <= 9999; i++) visited[i] = false;
		q.push(make_pair(start, ""));
		visited[start] = true;
		while (!q.empty()) {
			int here = q.front().first;
			string str = q.front().second;
			q.pop();

			int d = (here * 2) % 10000;
			int l = (here % 1000 / 100) * 1000 + (here % 100 / 10) * 100 + (here % 10) * 10 + here / 1000;
			int r = (here % 10) * 1000 + (here / 1000) * 100 + (here % 1000 / 100) * 10 + (here % 100 / 10);
			int s = (here - 1) >= 0 ? (here - 1) : 9999;

			if (d == goal) {
				result = str + "D";
				break;
			}

			if (s == goal) {
				result = str + "S";
				break;
			}

			if (l == goal) {
				result = str + "L";
				break;
			}

			if (r == goal) {
				result = str + "R";
				break;
			}

			if (!visited[d]) {
				visited[d] = true;
				q.push(make_pair(d, str + "D"));
			}

			if (!visited[s]) {
				visited[s] = true;
				q.push(make_pair(s, str + "S"));
			}

			if (!visited[l]) {
				visited[l] = true;
				q.push(make_pair(l, str + "L"));
			}

			if (!visited[r]) {
				visited[r] = true;
				q.push(make_pair(r, str + "R"));
			}
		}
		cout << result << "\n";
	}
}
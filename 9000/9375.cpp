#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		pair<string, string> p[31];
		map<string, int> m;
		int n, answer = 1;;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].second >> p[i].first;
			m.insert(make_pair(p[i].first, 0));
			m[p[i].first]++;
		}
		for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
			answer *= (iter->second + 1);
		}
		answer -= 1;
		cout << answer << "\n";
	}
}
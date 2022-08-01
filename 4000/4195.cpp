#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, pair<string, int>> par;

pair<string, int> find(string s) {
	if (par[s].first == s) return par[s];
	return par[s] = find(par[s].first);
}

void merge(string a, string b) {
	a = find(a).first;
	b = find(b).first;

	if (a == b) return;

	if (par[a].second > par[b].second) {
		par[a].second += par[b].second;
		par[b].first = a;
		par[b].second += par[a].second;
	}
	else {
		par[b].second += par[a].second;
		par[a].first = b;
		par[a].second = par[b].second;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int f;
		cin >> f;
		while (f--) {
			string a, b;
			cin >> a >> b;
			par.insert(make_pair(a, make_pair(a, 1)));
			par.insert(make_pair(b, make_pair(b, 1)));
			merge(a, b);
			cout << find(a).second << "\n";
		}
		par.clear();
	}
}
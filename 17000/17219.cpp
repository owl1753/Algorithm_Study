#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> mapp;
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		mapp.insert(make_pair(a, b));
	}
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		cout << mapp[a] << "\n";
	}
}
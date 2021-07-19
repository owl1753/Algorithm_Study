#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> map;
	vector<string> v;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		map.insert(make_pair(name, i));
		v.push_back(name);
	}
	for (int i = 1; i <= m; i++) {
		int index = 0;
		string k;
		cin >> k;
		for (int i = 0; i < k.size(); i++)
			index += (((int)pow(10, k.size() - i - 1)) * (k[i] - '0'));
		index--;
		if (map[k])
			cout << map[k] << "\n";
		else
			cout << v[index] << "\n";
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp1(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }
bool cmp2(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }

vector<pair<int, int>> v;
int n, m, k;
long long result = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp1);
	for (int i = 0; i < k; i++) result += v[i].first;
	v.erase(v.begin(), v.begin() + k);
	sort(v.begin(), v.end(), cmp2);
	for (int i = 0; i < m; i++) result += v[i].first;
	cout << result;
}
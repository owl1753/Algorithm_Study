#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<long long, long long>> x;
vector<pair<long long, long long>> sum;
long long n, m, a, b, result = 0;

bool cmp(pair<long long, long long> a, pair<long long, long long> b) { return a.first < b.first; }

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
		x.push_back(tmp);
	}
	cin >> m;
	sum.push_back(make_pair(-10987654321, 0));
	sum.push_back(make_pair(-10987654321, 0));
	for (int i = 0; i < m; i++) {
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
	    tmp.second += sum[i + 1].second;
		sum.push_back(tmp);
	}
	cin >> a;
	cin >> b;

	for (int i = 0; i < n; i++) {
		int l = lower_bound(sum.begin(), sum.end(), make_pair(a + x[i].first, 0), cmp) - sum.begin() - 1;
		int r = lower_bound(sum.begin(), sum.end(), make_pair(b + x[i].first, 0), cmp) - sum.begin();

		if (r >= sum.size()) result += (x[i].second * (sum[sum.size() - 1].second - sum[l].second));
		else {
			if (b + x[i].first < sum[r].first) r--;
			result += (x[i].second * (sum[r].second - sum[l].second));
		}
	}

	cout << result;
}
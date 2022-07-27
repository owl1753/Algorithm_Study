#include <iostream>
#include <set>
using namespace std;

set<pair<int, int>> s;
int leftEnd[1000001][2];
int rightEnd[1000001][2];
int n, q;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r, size;
		cin >> l >> r;
		size = r - l;
		leftEnd[l][0] = 1;
		if (leftEnd[l][1] < size) leftEnd[l][1] = size;
		rightEnd[r][0] = 1;
		if (rightEnd[r][1] < size) rightEnd[r][1] = size;
		s.insert(make_pair(l, r));
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r, size;
		cin >> l >> r;
		size = r - l;
		if (s.find(make_pair(l, r)) != s.end()) cout << "1" << "\n";
		else if (leftEnd[l][0] && rightEnd[r][0] && leftEnd[l][1] > size && rightEnd[r][1] > size) cout << "2" << "\n";
		else cout << "-1" << "\n";
	}
}
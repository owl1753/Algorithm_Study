#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101];
int n, index = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		v[0].push_back(i);
	}
	while (1) {
		if (v[index].size() == 1)
			break;
		for (int i = 0; i < n; i++) {
			if (i % 2)
				v[index + 1].push_back(v[index][i]);
		}
		index++;
		n /= 2;
	}
	cout << v[index][0];
}
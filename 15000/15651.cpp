#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void func(int k, int n, int m) {
	if (m == 0) {
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		func(i + 1, n, m - 1);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	func(1, n, m);
}
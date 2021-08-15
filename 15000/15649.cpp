#include <iostream>
#include <vector>
using namespace std;

int check[9];
vector<int> v;

void func(int k, int n, int m) {
	if (m == 0) {
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == 1)
			continue;
		v.push_back(i);
		check[i] = 1;
		func(i + 1, n, m - 1);
		v.pop_back();
		check[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	func(1, n, m);
}
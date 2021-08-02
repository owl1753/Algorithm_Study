#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int arr[8];
bool check[10001];
vector<int> v;
set<vector<int>> s;

void func(int k, int n, int m) {
	if (m == 0) {
		s.insert(v);
		return;
	}
	for (int i = k; i < n; i++) {
		if (check[i])
			continue;
		v.push_back(arr[i]);
		check[i] = true;
		func(0, n, m - 1);
		v.pop_back();
		check[i] = false;
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	func(0, n, m);
	for (set<vector<int>>::iterator iter = s.begin(); iter != s.end(); iter++) {
		for (int i = 0; i < (*iter).size(); i++) {
			printf("%d ", (*iter)[i]);
		}
		printf("\n");
	}
}
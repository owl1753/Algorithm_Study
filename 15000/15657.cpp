#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[8];
vector<int> v;

void func(int k, int n, int m) {
	if (m == 0) {
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (int i = k; i < n; i++) {
		v.push_back(arr[i]);
		func(i, n, m - 1);
		v.pop_back();
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	func(0, n, m);
}
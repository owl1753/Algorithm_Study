#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int n, m;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	scanf("%d", &m);
	while (m--) {
		int k;
		scanf("%d", &k);
		printf("%d ", upper_bound(arr, arr + n, k) - lower_bound(arr, arr + n, k));
	}
}
#include <iostream>
using namespace std;

int arr[1000001];
int cnt[2000001];

int main() {
	int n, index = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		cnt[arr[i] + 1000000]++;
	}
	for (int i = 2000000; i >= 0; i--) {
		while (cnt[i]) {
			printf("%d\n", i - 1000000);
			cnt[i]--;
		}
	}
}
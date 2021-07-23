#include <iostream>
using namespace std;

int main() {
	int n, result = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int sum = i, t = i;
		while (t) {
			sum += t % 10;
			t /= 10;
		}
		if (sum == n) {
			result = i;
			break;
		}
	}
	printf("%d", result);
}
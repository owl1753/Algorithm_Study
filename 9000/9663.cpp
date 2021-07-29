#include <iostream>
#include <math.h>
using namespace std;
#define MAX 16

int check[MAX];
int n, cnt = 0;

bool isTrue(int k) {
	for (int i = 1; i < k; i++) {
		if (check[i] == check[k] || (abs(check[k] - check[i]) == k - i))
			return false;
	}
	return true;
}

void func(int k) {
	if (k == n + 1) {
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		check[k] = i;
		if (isTrue(k))
			func(k + 1);
	}
}

int main() {
	scanf("%d", &n);
	func(1);
	printf("%d", cnt);
}
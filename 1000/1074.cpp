#include <iostream>
#include <math.h>
using namespace std;

int i_pow(int a, int b) { return (int)pow(a, b); }

int answer, flag = 0;

void func(int x, int y, int n, int r, int c) {
	if ((x == c && y == r) || flag == 1) {
		flag = 1;
		return;
	}
	if (x - i_pow(2, n - 1) >= c && y - i_pow(2, n - 1) >= r) {
		answer -= (i_pow(2, n - 1) * i_pow(2, n - 1) * 3);
		func(x - i_pow(2, n - 1), y - i_pow(2, n - 1), n - 1, r, c);
	}
	if (c > x - i_pow(2, n - 1) && y - i_pow(2, n - 1) >= r) {
		answer -= (i_pow(2, n - 1) * i_pow(2, n - 1) * 2);
		func(x, y - i_pow(2, n - 1), n - 1, r, c);
	}
	if (x - i_pow(2, n - 1) >= c && r > y - i_pow(2, n - 1)) {
		answer -= (i_pow(2, n - 1) * i_pow(2, n - 1) * 1);
		func(x - i_pow(2, n - 1), y, n - 1, r, c);
	}
	if (c > x - i_pow(2, n - 1) && r > y - i_pow(2, n - 1)) {
		func(x, y, n - 1, r, c);
	}
}

int main() {
	int n, r, c;
	scanf("%d%d%d", &n, &r, &c);
	r += 1; c += 1; answer = i_pow(2, n) * i_pow(2, n) - 1;
	func((int)pow(2, n), (int)pow(2, n), n, r, c);
	printf("%d", answer);
}
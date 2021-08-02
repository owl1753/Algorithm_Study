#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 11
#define INF 2000000000

int A[MAX];
int oper[4];
int n, result1, result2;

int func1(int n, int oper_1, int oper_2, int oper_3, int oper_4) {
	int t = -2000000000;
	if (n == 0)
		return A[n];
	if (oper_1 > 0) {
		t = max(t, func1(n - 1, oper_1 - 1, oper_2, oper_3, oper_4) + A[n]);
	}
	if (oper_2 > 0) {
		t = max(t, func1(n - 1, oper_1, oper_2 - 1, oper_3, oper_4) - A[n]);
	}
	if (oper_3 > 0) {
		t = max(t, func1(n - 1, oper_1, oper_2, oper_3 - 1, oper_4) * A[n]);
	}
	if (oper_4 > 0) {
		t = max(t, func1(n - 1, oper_1, oper_2, oper_3, oper_4 - 1) / A[n]);
	}
	return t;
}

int func2(int n, int oper_1, int oper_2, int oper_3, int oper_4) {
	int t = INF;
	if (n == 0)
		return A[n];
	if (oper_1 > 0) {
		t = min(t, func2(n - 1, oper_1 - 1, oper_2, oper_3, oper_4) + A[n]);
	}
	if (oper_2 > 0) {
		t = min(t, func2(n - 1, oper_1, oper_2 - 1, oper_3, oper_4) - A[n]);
	}
	if (oper_3 > 0) {
		t = min(t, func2(n - 1, oper_1, oper_2, oper_3 - 1, oper_4) * A[n]);
	}
	if (oper_4 > 0) {
		t = min(t, func2(n - 1, oper_1, oper_2, oper_3, oper_4 - 1) / A[n]);
	}
	return t;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &oper[i]);
	result1 = func1(n - 1, oper[0], oper[1], oper[2], oper[3]);
	result2 = func2(n - 1, oper[0], oper[1], oper[2], oper[3]);
	printf("%d\n%d", result1, result2);
}
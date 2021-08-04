#include <iostream>
#define MAX 11

int A[MAX];
int n, a = 1, b = 1, c = 1, d = 1, max = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int i = 1; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				for (int l = 0; l < i; l++) {
					a *= A[l];
				}
				for (int l = i; l < j; l++) {
					b *= A[l];
				}
				for (int l = j; l < k; l++) {
					c *= A[l];
				}
				for (int l = k; l < n; l++) {
					d *= A[l];
				}
				if (max < (a + b + c + d))
					max = a + b + c + d;
				a = 1; b = 1; c = 1; d = 1;
			}
		}
	}
	printf("%d", max);
}
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			printf(" ");
		}
		for (int j = 1; j <= n; j++) {
			printf("* ");
		}
		printf("\n");
	}
}
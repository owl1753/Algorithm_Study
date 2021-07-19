#include <iostream>
using namespace std;

int main() {
	int n, tcnt = 0, fcnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int k = i;
		while (!(k % 2)) {
			tcnt++;
			k /= 2;
		}
		while (!(k % 5)) {
			fcnt++;
			k /= 5;
		}
	}
	printf("%d", fcnt < tcnt ? fcnt : tcnt);
}
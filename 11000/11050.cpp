#include <iostream>
using namespace std;

int fact[11];
int n, k;

int main() {
	fact[0] = 1;
	for (int i = 1; i <= 10; i++) {
		fact[i] = fact[i - 1] * i;
	}
	scanf("%d%d", &n, &k);
	printf("%d", fact[n] / (fact[n - k] * fact[k]));
}
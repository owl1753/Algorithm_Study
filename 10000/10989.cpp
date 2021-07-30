#include <iostream>
using namespace std;

int check[10001];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		check[k]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < check[i]; j++) {
			printf("%d\n", i);
		}
	}
}
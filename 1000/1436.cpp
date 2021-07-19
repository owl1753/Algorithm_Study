#include <iostream>
using namespace std;
#define M 10000000

int main() {
	int n, order = 0;
	scanf("%d", &n);
	for (int i = 666; i <= M; i++) {
		int t = i;
		int cnt = 0;
		while (t) {
			if (t % 10 == 6)
				cnt++;
			else
				cnt = 0;
			if (cnt == 3)
				break;
			t /= 10;
		}
		if (cnt >= 3)
			order++;
		if (order == n) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}
#include <iostream>
using namespace std;
#define MAX 100001

int n, cnt = 0, sum = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int h;
		scanf("%d", &h);
		cnt += (h / 2);
		sum += h;
	}
	if (cnt >= sum / 3 && sum % 3 == 0)
		printf("YES");
	else
		printf("NO");
}
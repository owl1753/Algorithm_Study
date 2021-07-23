#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n;

int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("1");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (1) {
		q.pop();
		int number = q.front();
		if (q.size() == 1) {
			printf("%d", number);
			break;
		}
		q.pop();
		q.push(number);
	}
}
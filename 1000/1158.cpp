#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n, k;

int main() {
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	printf("<");
	while (!q.empty()) {
		int number;
		for (int i = 0; i < k - 1; i++) {
			number = q.front();
			q.pop();
			q.push(number);
		}
		number = q.front();
		q.pop();
		if (q.size() > 0)
			printf("%d, ", number);
		else
			printf("%d>", number);
	}
}
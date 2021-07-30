#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 500001

int card[MAX];
int n, m;

int search(int k) {
	int left = 0, right = n - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (card[mid] == k)
			return 1;
		if (card[mid] < k)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &card[i]);
	scanf("%d", &m);
	sort(card, card + n);
	while (m--) {
		int k;
		scanf("%d", &k);
		printf("%d\n", search(k));
	}
}
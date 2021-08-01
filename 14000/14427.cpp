#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int tree[MAX * 4];
int A[MAX];
int n, m;

int update(int index, int start, int end, int target) {
	if (target < start || target > end)
		return tree[index];
	if (start == end)
		return tree[index] = target;
	int mid = (start + end) / 2;
	int first = update(index * 2, start, mid, target);
	int second = update(index * 2 + 1, mid + 1, end, target);
	if (A[first] == A[second])
		return tree[index] = min(first, second);
	if (A[first] < A[second])
		return tree[index] = first;
	if (A[first] > A[second])
		return tree[index] = second;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		update(1, 1, n, i);
	}
	scanf("%d", &m);
	while (m--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int i, v;
			scanf("%d%d", &i, &v);
			A[i] = v;
			update(1, 1, n, i);
		}
		else {
			printf("%d\n", tree[1]);
		}
	}
}
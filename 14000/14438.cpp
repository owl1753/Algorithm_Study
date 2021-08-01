#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
#define INF 1000000001

int tree[MAX * 4];
int A[MAX];
int n, m;

int update(int index, int start, int end, int target, int diff) {
	if (target < start || target > end)
		return tree[index];
	if (start == end)
		return tree[index] = diff;
	int mid = (start + end) / 2;
	return tree[index] = min(update(index * 2, start, mid, target, diff), update(index * 2 + 1, mid + 1, end, target, diff));
}

int query(int index, int start, int end, int left, int right) {
	if (end < left || start > right)
		return INF;
	if (left <= start && end <= right)
		return tree[index];
	int mid = (start + end) / 2;
	return  min(query(index * 2, start, mid, left, right), query(index * 2 + 1, mid + 1, end, left, right));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		update(1, 1, n, i, A[i]);
	}
	scanf("%d", &m);
	while (m--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int i, v;
			scanf("%d%d", &i, &v);
			update(1, 1, n, i, v);
		}
		else {
			int i, j;
			scanf("%d%d", &i, &j);
			printf("%d\n", query(1, 1, n, i, j));
		}
	}
}
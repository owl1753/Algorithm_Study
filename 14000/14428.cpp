#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
#define INF 2000000001

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

int query(int index, int start, int end, int left, int right) {
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return tree[index];
	int mid = (start + end) / 2;
	int first = query(index * 2, start, mid, left, right);
	int second = query(index * 2 + 1, mid + 1, end , left, right);
	if (A[first] == A[second])
		return min(first, second);
	if (A[first] < A[second])
		return first;
	if (A[first] > A[second])
		return second;
}

int main() {
	scanf("%d", &n);
	A[0] = INF;
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
			int i, j;
			scanf("%d%d", &i, &j);
			printf("%d\n", query(1, 1, n, i, j));
		}
	}
}
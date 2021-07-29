#include <iostream>
#include <vector>
using namespace std;
#define MAX 4000001
#define ll long long

ll tree[MAX];
ll A[MAX];
ll check[MAX];
ll n, result = 0;

ll update(ll start, ll end, ll index, ll target) {
	if (target < start || target > end)
		return tree[index];
	if (start == end)
		return tree[index] = 1;
	int mid = (start + end) / 2;
	return tree[index] = update(start, mid, index * 2, target) + update(mid + 1, end, index * 2 + 1, target);
}

ll query(ll start, ll end, ll index, ll left, ll right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index];
	int mid = (start + end) / 2;
	return query(start, mid, index * 2, left, right) + query(mid + 1, end, index * 2 + 1, left, right);
}

int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) { 
		ll t;
		scanf("%lld", &t);
		check[t] = i;
	}
	for (int i = 1; i <= n; i++) {
		ll t;
		scanf("%lld", &t);
		A[i] = check[t];
	}
	for (int i = 1; i <= n; i++) {
		update(1, n, 1, A[i]);
		result += query(1, n, 1, A[i] + 1, n);
	}
	printf("%lld", result);
}
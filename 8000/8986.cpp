#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const long long INF = 1e18;

long long x[100001];
long long n;
long long result = INF;

long long func(long long x0) {
	long long temp = 0;
	for (long long i = 0; i < n; i++) {
		temp += abs((i * x0) - x[i]);
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	long long left = 0, right = x[n - 1], p, q;
	while (right - left >= 3) {
		p = (right + 2 * left) / 3; 
		q = (2 * right + left) / 3;
		if (func(p) > func(q)) left = p;
		else right = q;
	}

	for (long long i = left; i <= right; i++) {
		result = min(func(i), result);
	}
	cout << result;
}
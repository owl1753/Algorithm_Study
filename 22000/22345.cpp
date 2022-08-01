#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

pair<long long, long long> arr[200001];
long long sum1[200001];
long long sum2[200001];
int n, q;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) { return a.second < b.second; }

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int a, x;
		cin >> a >> x;
		arr[i] = make_pair(a, x);
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			sum1[i] = abs(arr[i].first * arr[i].second);
			sum2[i] = arr[i].first;
		}
		else {
			sum1[i] = abs(arr[i].first * arr[i].second) + sum1[i - 1];
			sum2[i] = arr[i].first + sum2[i - 1];
		}
	}
	for (int i = 0; i < q; i++) {
		long long result = 0, x, idx1, idx2;
		cin >> x;
		idx1 = lower_bound(arr, arr + n, make_pair(0, x), cmp) - arr - 1;
		idx2 = lower_bound(arr, arr + n, make_pair(0, 0), cmp) - arr - 1;
		if (idx1 < 0 && idx2 < 0) {
			result = sum1[n - 1] - (sum2[n - 1] * x);
		}
		else if (idx1 < 0) {
			result = ((-x * sum2[idx2]) - sum1[idx2]) +
				((sum1[n - 1] - sum1[idx2]) - ((sum2[n - 1] - sum2[idx2]) * x));
		}
		else if (idx2 < 0) {
			result = ((sum2[idx1] * x) - sum1[idx1]) +
				((sum1[n - 1] - sum1[idx1]) - ((sum2[n - 1] - sum2[idx1]) * x));
		}
		else {
			if (x > 0) {
				result = (sum1[idx2] + (x * sum2[idx2])) +
					(((sum2[idx1] - sum2[idx2]) * x) - (sum1[idx1] - sum1[idx2])) +
					((sum1[n - 1] - sum1[idx1]) - ((sum2[n - 1] - sum2[idx1]) * x));
			}
			else {
				result = (sum1[idx1] + (x * sum2[idx1])) +
					(((sum2[idx2] - sum2[idx1]) * -x) - (sum1[idx2] - sum1[idx1])) +
					((sum1[n - 1] - sum1[idx2]) - ((sum2[n - 1] - sum2[idx2]) * x));
			}
			
		}
		cout << result << "\n";
	}
}
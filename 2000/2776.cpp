#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int brr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> brr[i];
		sort(arr, arr + n);
		for (int i = 0; i < m; i++) {
			int result = 0;
			int k = brr[i];
			int left = 0, right = n - 1, mid;
			while (left <= right) {
				mid = (left + right) / 2;
				if (arr[mid] == k) {
					result = 1;
					break;
				}
				else if (arr[mid] < k) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			cout << result << "\n";
		}
	}
}
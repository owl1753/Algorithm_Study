#include <iostream>
using namespace std;

int arr[200001];
int n, result = 1, idx = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] < arr[idx])
			idx = i;
	}
	idx++;
	for (int i = 1; i < n; i++) {
		if (idx > n) {
			result = 2;
			idx = 1;
			if (arr[idx] < arr[n]) {
				result = 3;
				break;
			}
		}
		else {
			if (arr[idx] < arr[idx - 1]) {
				result = 3;
				break;
			}
		}
		idx++;
	}
	cout << result;
}
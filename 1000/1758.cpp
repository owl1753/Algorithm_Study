#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int n;
long long result = 0;
bool cmp(int a, int b) { return a > b; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		int tmp = arr[i] - i;
		if (tmp > 0) result += tmp;
	}
	cout << result;
}
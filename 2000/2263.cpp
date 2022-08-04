#include <iostream>
using namespace std;

int arr[200001];
int brr[200001];
int n;

void func(int l1, int r1, int l2, int r2) {
	if (l1 >= r1 || l2 >= r2) {
		if (l1 == r1 && l2 == r2) cout << arr[l1] << " ";
		return;
	}

	int mid = 0;
	int tmp = brr[r2];

	for (int i = l1; i <= r1; i++) {
		if (arr[i] == tmp) {
			mid = i;
			break;
		}
	}
	
	cout << tmp << " ";
	func(l1, mid - 1, l2, l2 + (mid - l1 - 1));
	func(mid + 1, r1, l2 + (mid - l1), r2 - 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) cin >> brr[i];
	func(0, n - 1, 0, n - 1);
}
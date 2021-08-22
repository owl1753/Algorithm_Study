#include <iostream>
using namespace std;

int arr[100001];
int n, cond = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 2; i <= n; i++) {
		if ((arr[i] > arr[i - 1] && cond == 1) || arr[i] == arr[i - 1]) {
			cout << "NO";
			return 0;
		}
		if (arr[i] < arr[i - 1] && cond == 0)
			cond = 1;
	}
	cout << "YES";
}
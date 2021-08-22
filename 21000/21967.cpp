#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int n, l = 1, r = 3, result = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	while (r <= 10) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt++;
			if (arr[i] < l || r < arr[i]) {
				cnt--;
				result = max(result, cnt);
				cnt = 0;
			}	
		}
		result = max(result, cnt);
		l++;
		r++;
	}
	cout << result;
}
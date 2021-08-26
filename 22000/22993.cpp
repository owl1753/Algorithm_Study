#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];
int n;
long long sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a + 1, a + n);
	sum = a[0];
	for (int i = 1; i < n; i++) {
		if (sum > a[i])
			sum += a[i];
		else {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}
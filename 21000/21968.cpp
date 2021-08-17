#include <iostream>
using namespace std;

long long pow(int a, int b) {
	long long result = 1;
	for (int i = 1; i <= b; i++) {
		result *= a;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		long long n, result = 0;
		int cnt = 0;
		cin >> n;
		while (n) {
			if (n % 2) {
				result += pow(3, cnt);
			}
			cnt++;
			n /= 2;
		}
		cout << result << "\n";
	}
}
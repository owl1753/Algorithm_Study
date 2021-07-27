#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m, x, y, result = -1;
		cin >> n >> m >> x >> y;
		if (n == x && m == y) {
			cout << (n * m) / 2;
			continue;
		}
		for (int i = (x % n); i <= n * m; i += n) {
			if (i % m == y || m == y && i % m == 0) {
				result = i;
				break;
			}
		}
		cout << result << "\n";
	}
}
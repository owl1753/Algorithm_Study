#include <iostream>
#include <string>
using namespace std;

int result[11111];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a, b;
	int len = 0, k = 0;
	cin >> a >> b;
	for (int i = 0; i < 11111; i++) {
		if ((int)a.length() - i - 1 < 0 && (int)b.length() - i - 1 < 0 && k == 0)
			break;
		if ((int)a.length() - i - 1 >= 0) {
			result[i] += (a[a.length() - i - 1] - '0');
		}
		if ((int)b.length() - i - 1 >= 0) {
			result[i] += (b[b.length() - i - 1] - '0');
		}
		result[i] += k;
		k = result[i] / 10;
		result[i] = result[i] % 10;
		len++;
	}
	for (int i = len - 1; i >= 0; i--) {
		cout << result[i];
	}
}
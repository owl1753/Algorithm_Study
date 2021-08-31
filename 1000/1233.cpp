#include <iostream>
using namespace std;

int check[1001];
int s1, s2, s3, result = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s1 >> s2 >> s3;
	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			for (int k = 1; k <= s3; k++) {
				check[i + j + k]++;
			}
		}
	}
	for (int i = 2; i <= 1000; i++) {
		if (check[i] > check[result])
			result = i;
	}
	cout << result;
}
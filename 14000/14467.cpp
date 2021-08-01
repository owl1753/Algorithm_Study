#include <iostream>
using namespace std;;

int arr[11];
int n, answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (arr[a] == 1 && b == 1) {
			answer++;
		}
		else if (arr[a] == 2 && b == 0) {
			answer++;
		}
		arr[a] = b + 1;
	}
	cout << answer;
}
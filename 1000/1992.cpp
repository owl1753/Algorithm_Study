#include <iostream>
#include <vector>
using namespace std;

char arr[65][65];
vector<char> v;

void func(int x, int y, int r, int c, int n) {
	char hdot = arr[x - 1][y - 1];
	int flag = 1;
	for (int i = x - 1; i < r; i++) {
		if (flag == 0)
			break;
		for (int j = y - 1; j < c; j++) {
			if (arr[i][j] != hdot) {
				flag = 0;
				break;
			}
		}
	}
	if (flag == 1) {
		v.push_back(hdot);
	}
	else {
		v.push_back('(');
		func(x, y, r - (n / 2), c - (n / 2), n / 2);
		func(x, y + (n / 2), r - (n / 2), c, n / 2);
		func(x + (n / 2), y, r, c - (n / 2), n / 2);
		func(x + (n / 2), y + (n / 2), r, c, n / 2);
		v.push_back(')');
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %c", &arr[i][j]);
	func(1, 1, n, n, n);
	for (int i = 0; i < v.size(); i++)
		printf("%c", v[i]);
}
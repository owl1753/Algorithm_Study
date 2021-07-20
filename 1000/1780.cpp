#include <iostream>
using namespace std;

int map[2200][2200];
int n, cnt1 = 0, cnt2 = 0, cnt3 = 0;

void func(int x, int y, int r, int c, int n) {
	int hcolor = map[x][y];
	int flag = 1;
	for (int i = x; i <= r; i++) {
		if (flag == 0)
			break;
		for (int j = y; j <= c; j++) {
			if (hcolor != map[i][j]) {
				flag = 0;
				break;
			}
		}
	}
	if (flag == 1) {
		if (hcolor == -1)
			cnt1++;
		else if (hcolor == 0)
			cnt2++;
		else
			cnt3++;
		return;
	}
	else {
		func(x, y, r - (2 * (n / 3)), c - (2 * (n / 3)), n / 3);
		func(x, y + (n / 3), r - (2 * (n / 3)), c - (n / 3), n / 3);
		func(x, y + (2 * (n / 3)), r - (2 * (n / 3)), c, n / 3);
		func(x + (n / 3), y, r - (n / 3), c - (2 * (n / 3)), n / 3);
		func(x + (n / 3), y + (n / 3), r - (n / 3), c - (n / 3), n / 3);
		func(x + (n / 3), y + (2 * (n / 3)), r - (n / 3), c, n / 3);
		func(x + (2 * (n / 3)), y, r, c - (2 * (n / 3)), n / 3);
		func(x + (2 * (n / 3)), y + (n / 3), r, c - (n / 3), n / 3);
		func(x + (2 * (n / 3)), y + (2 * (n / 3)), r, c, n / 3);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);
	func(1, 1, n, n, n);
	printf("%d\n%d\n%d", cnt1, cnt2, cnt3);
}